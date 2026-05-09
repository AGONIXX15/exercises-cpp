#pragma once
#include <format>
#include <iomanip>
#include <lexer/TokenKind.hpp>
#include <string>

struct Token {
  TokenKind kind;
  int pos;
  std::string value;
};

template <> struct std::formatter<Token> {
  bool debug_mode = false;
  constexpr void set_debug_format() { debug_mode = true; }

  auto format(const Token &t, auto &ctx) const {
    if (debug_mode) {
      return std::format_to(ctx.out(), "Token(kind={}, pos={}, value={})",
                            t.kind t.pos, )
    }
  }
};
