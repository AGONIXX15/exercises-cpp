#pragma once
#include <regex/Token.hpp>
#include <regex/TokenType.hpp>

#include <vector>
class Parser {

  bool needs_concat(TokenType left, TokenType right);

public:
  std::vector<Token> tokens;
  Parser(const std::vector<Token> &t) : tokens(std::move(t)) {}
  void insert_concat();
  void convert_into_postfix();
};
