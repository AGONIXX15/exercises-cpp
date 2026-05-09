#pragma once

#include <fstream>
#include <optional>


struct Lexer {
  
  std::ifstream file;
  std::size_t line = 1;
  std::size_t column = 1;
  std::size_t pos = 0;

  Lexer(std::ifstream&& file);

  ~Lexer();

  std::optional<char> get_char();
};
