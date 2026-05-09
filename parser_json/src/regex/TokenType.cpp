#include <regex/TokenType.hpp>

const char *kind_to_string(TokenType kind) {
  switch (kind) {
  case TokenType::LPAREN:
    return "LPAREN";
  case TokenType::RPAREN:
    return "RPAREN";
  case TokenType::CHAR:
    return "CHAR";
  case TokenType::CONCAT:
    return "CONCAT";
  case TokenType::END:
    return "END";
  case TokenType::OR:
    return "OR";
  case TokenType::STAR:
    return "STAR";
  default:
    return "IDK";
  }
}
