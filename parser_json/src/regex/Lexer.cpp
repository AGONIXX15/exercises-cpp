#include "regex/TokenType.hpp"
#include <regex/Lexer.hpp>
#include <regex/Token.hpp>
#include <vector>

Token Lexer::next() {
  if (pos >= input.size()) {
    return {TokenType::END};
  }

  while (pos < input.size() && input[pos] == ' ')
    pos++;
  char c = input[pos++];
  switch (c) {
  case '*':
    return {TokenType::STAR};

  case '|':
    return {TokenType::OR};

  case '(':
    return {TokenType::LPAREN};

  case ')':
    return {TokenType::RPAREN};

  default:
    return {TokenType::CHAR, c};
  }
}

std::vector<Token> Lexer::get_tokens() {
  std::vector<Token> v;
  Token t = next();
  while (t.kind != TokenType::END) {
    v.push_back(t);
    t = next();
  }
  v.push_back(t);
  return v;
}
