#pragma once
#include <regex/Token.hpp>
#include <string>
#include <vector>

class Lexer {
  std::string input;
  std::size_t pos = 0;

public:
  Lexer(std::string s) : input(std::move(s)) {}

  Token next();
  // for the use pos need to be on zero
  std::vector<Token> get_tokens();
};
