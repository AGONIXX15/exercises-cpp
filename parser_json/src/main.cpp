#include <print>
#include <regex/Lexer.hpp>
#include <regex/Parser.hpp>
#include <vector>

int main() {
  Lexer lex("abc*bc*");
  std::vector<Token> tokens = lex.get_tokens();

  for (auto &tok : tokens)
    std::println("{}", tok);
  std::println("");
  Parser parser(tokens);
  parser.insert_concat();
  for (auto &tok : parser.tokens)
    std::println("{}", tok);
  std::println("");
  parser.convert_into_postfix();
  for (auto &tok : parser.tokens)
    std::println("{}", tok);

  return 0;
}
