#pragma once
#include <lexer/Token.hpp>
#include <string>
#include <vector>

class Lexer {
  std::string value;
  int pos = 0;
  void advance() { pos++; }

public:
  Lexer(std::string &value);

  std::vector<Token> lex();
};
