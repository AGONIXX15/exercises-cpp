#include "lexer/utils.hpp"
#include <string>
#include <unordered_set>

bool is_operator(char c) {
  static const std::unordered_set<char> operators = {'*', '+', '-',
                                                     '/', '|', '&'};
  return operators.contains(c);
}
