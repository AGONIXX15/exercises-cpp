#include "Persona.hpp"
#include <format>
#include <print>
#include "lexer/Lexer.hpp"
#include <fstream>

int main() {
  std::ifstream file("text.txt");
  Lexer l(std::move(file));



  return 0;
}
