#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

enum class TokenKind { Number, Add, Mul, Sub, Div, LParen, RParen };

std::ostream &operator<<(std::ostream &os, const TokenKind kind) {
  if (kind == TokenKind::Number) {
    os << "Number";
  } else if (kind == TokenKind::Add) {
    os << "Add";
  } else if (kind == TokenKind::Mul) {
    os << "Mul";
  } else if (kind == TokenKind::Sub) {
    os << "Sub";
  } else {
    os << "Div";
  }
  return os;
}

struct Token {
  std::string value;
  TokenKind kind;
};

std::pair<Token, size_t> token_integer(std::string str, int index) {
  int start = index;
  int size = 0;
  while (std::isdigit(str[index]) && index < str.size()) {
    index++;
    size++;
  }

  std::string res = str.substr(start, size);
  return {Token{res, TokenKind::Number}, size};
}

Token token_operator(std::string c) {

  std::unordered_map<char, TokenKind> dct = {
      {'+', TokenKind::Add},
      {'*', TokenKind::Mul},
      {'-', TokenKind::Sub},
      {'/', TokenKind::Div},

  };

  return Token{c, dct[c[0]]};
}

bool is_operator(char c) {
  switch (c) {
  case '+':
    return true;
  case '-':
    return true;
  case '*':
    return true;
  case '/':
    return true;
  default:
    return false;
  }
}

std::vector<Token> tokenize(std::string lexme) {

  std::vector<Token> v;

  for (size_t i = 0; i < lexme.size(); ++i) {
    if (std::isdigit(lexme[i])) {
      auto [t, s] = token_integer(lexme, i);
      v.push_back(t);
      i += s - 1;
    } else if (is_operator(lexme[i])) {
      v.push_back(token_operator(std::string(1, lexme[i])));
    }
  }
  return v;
}

std::ostream &operator<<(std::ostream &os, const Token &t) {
  os << "Token(value=\"" << t.value << "\", kind=" << t.kind << ")";
  return os;
}

enum class Importance { Default, Add, Mul, Pow, Primary };

struct Expr {

  virtual int evaluate() = 0;
};

struct Number : Expr {
  int n;
  Number(int n) : n(n) {}

  int evaluate() { return n; }
};

struct BinaryExpr : Expr {
  std::unique_ptr<Expr> left;
  std::unique_ptr<Expr> right;
  TokenKind op;

  int evaluate() {
    int l = left->evaluate();
    int r = right->evaluate();
    switch (op) {
    case TokenKind::Add:
      return l + r;
    case TokenKind::Sub:
      return l - r;
    case TokenKind::Mul:
      return l * r;
    case TokenKind::Div:
      return l / r;
    default:
      return 0;
    }
  }
};

struct UnaryExpr : Expr {
  TokenKind op;
  std::unique_ptr<Expr> left;

  UnaryExpr(std::unique_ptr<Expr>&& left, TokenKind op)
      : left(std::move(left)), op(op) {
  }

  int evaluate() {
    int l = left->evaluate();
    switch (op) {
    case TokenKind::Sub:
      return -l;
    default:
      return 0;
    }
  }
};

std::unordered_map<TokenKind, Importance> importance;
void initialize() {
  importance[TokenKind::Add] = Importance::Add;
  importance[TokenKind::Sub] = Importance::Add;
  importance[TokenKind::Mul] = Importance::Mul;
  importance[TokenKind::Div] = Importance::Mul;
}

Number parse_integer(Token &t) { return Number{std::stoi(t.value)}; }

struct Parser {

  std::vector<Token> v;
  size_t pos = 0;
  Parser(std::vector<Token> &&v) : v(std::move(v)) { initialize(); }

  Token get_token() { return v[pos]; }

  std::unique_ptr<Expr> parse_primary_expr() {
    Token t = get_token();
    if (t.kind == TokenKind::Number)
      return std::make_unique<Number>(std::stoi(t.value));
    else if (t.kind == TokenKind::Sub) {
      pos++;
      return std::make_unique<UnaryExpr>(parse_primary_expr(),t.kind);
    } else if(t.kind == TokenKind::LParen) {
      pos++;
      auto result = parse_expr(Importance::Default);
      pos++; // consume RParen
      return result;
    }

    return nullptr;
  }

  std::unique_ptr<Expr> parse_expr(Importance current) {
    auto left = parse_primary_expr();
    pos++;

    while (pos < v.size()) {
      Token op = get_token();

      auto op_importance = importance[op.kind];
      if (op_importance <= current)
        break;

      pos++;
      auto right = parse_expr(op_importance);

      auto node = std::make_unique<BinaryExpr>();
      node->op = op.kind;
      node->left = std::move(left);
      node->right = std::move(right);
      left = std::move(node);
    }

    return left;
  }
};

std::ostream& operator<<(std::ostream& os, const Number& num) {
  os << "Number(" << num.n << ")";
  return os;
}

std::ostream& operator<<(std::ostream& os, const BinaryExpr& bin) {
  os << "BinaryExpr(left="<< bin.left->evaluate() << " ,op=" << bin.op << ", right=" << bin.right->evaluate() << ")";
  return os;
}

std::ostream& operator<<(std::ostream& os, const Expr& expr) {
  os << expr;
  return os;
}


int main(void) {

  std::string s;
  std::getline(std::cin, s);

  std::cout << s << std::endl;

  if (s.empty())
    return 0;

  std::vector<Token> tokens = tokenize(s);
  for (auto t : tokens) {
    std::cout << t << '\n';
  }

  Parser p(std::move(tokens));

  auto expr = p.parse_expr(Importance::Default);

  std::cout << "result: " <<  expr->evaluate() << '\n';
}
