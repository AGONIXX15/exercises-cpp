#include "lexer/Lexer.hpp"

Lexer::Lexer(std::ifstream&& file): file(std::move(file)){}

Lexer::~Lexer() {
  file.close();
}
