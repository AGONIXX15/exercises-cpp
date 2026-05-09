#pragma once
#include <format>
#include <regex/TokenType.hpp>

struct Token {
  TokenType kind;
  char value;
};

template <> struct std::formatter<Token> {
  bool debug_mode = false;
  constexpr void set_debug_format() { debug_mode = true; }

  constexpr auto parse(auto &ctx) { return ctx.begin(); }
  auto format(Token &t, auto &ctx) const {
    if (debug_mode) {
      return std::format_to(ctx.out(), "Token(kind={}, value={})",
                            kind_to_string(t.kind), t.value);
    }
    return std::format_to(ctx.out(), "Token(kind={}, value={})",
                          kind_to_string(t.kind), t.value);
  }
};
