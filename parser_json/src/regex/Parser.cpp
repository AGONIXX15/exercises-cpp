#include <print>
#include <regex/Parser.hpp>
#include <regex/TokenType.hpp>
#include <stack>
#include <vector>

bool Parser::needs_concat(TokenType left, TokenType right) {

  bool left_ok = left == TokenType::RBRACKET || left == TokenType::RPAREN ||
                 left == TokenType::STAR || left == TokenType::CHAR;

  bool right_ok = right == TokenType::CHAR || right == TokenType::LPAREN ||
                  right == TokenType::LBRACKET;
  return left_ok && right_ok;
}

int precedence(TokenType kind) {
  switch (kind) {
  case TokenType::STAR:
    return 4;
  case TokenType::OR:
    return 2;
  case TokenType::CONCAT:
    return 3;
  default:
    return 0;
  }
}
std::vector<char> arr = {'(', ')', '|', '[', ']', '*'};

void Parser::insert_concat() {

  std::vector<Token> new_tokens;
  for (int i = 0; i + 1 < tokens.size(); ++i) {
    new_tokens.push_back(tokens[i]);
    if (needs_concat(tokens[i].kind, tokens[i + 1].kind))
      new_tokens.push_back(Token{TokenType::CONCAT});
  }

  if (!tokens.empty())
    new_tokens.push_back(tokens.back());
  tokens = std::move(new_tokens);
}

void Parser::convert_into_postfix() {
  std::vector<Token> ops;
  std::vector<Token> output;
  for (int i = 0; i < tokens.size() - 1; ++i) {

    Token tk = tokens[i];
    if (tk.kind == TokenType::CHAR) {
      output.push_back(tk);
    } else if (tk.kind == TokenType::LPAREN) {
      ops.push_back(tk);
    } else if (tk.kind == TokenType::RPAREN) {
      while (!ops.empty() && ops.back().kind != TokenType::LPAREN) {
        output.push_back(ops.back());
        ops.pop_back();
      }
      if (ops.empty()) {
        throw std::runtime_error("Parentesis desbalanceado");
      }
      ops.pop_back();
    } else if (tk.kind == TokenType::LBRACKET) {
      // TODO: handles ors
    } else {

      const auto o1 = tk;
      while (!ops.empty()) {
        auto o2 = ops.back();
        if (precedence(o2.kind) > precedence(o1.kind)) {
          ops.pop_back();
          output.push_back(o2);
          continue;
        }
        break;
      }
      ops.push_back(o1);
    }
  }

  while (!ops.empty()) {
    output.push_back(ops.back());
    ops.pop_back();
  }
  tokens = std::move(output);
}
