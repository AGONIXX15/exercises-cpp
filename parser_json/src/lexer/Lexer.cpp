#include <lexer/Lexer.hpp>

Lexer::Lexer(std::string &value) { this->value = std::move(value); }

std::vector<Token> Lexer::lex() {
  // TODO::
  while (pos < value.size()) {
  }

  return {};
}
