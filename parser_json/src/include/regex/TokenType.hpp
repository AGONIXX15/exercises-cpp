#pragma once

enum class TokenType {
  CHAR,

  STAR,
  OR,
  LBRACKET,
  RBRACKET,

  CONCAT,

  LPAREN, // (
  RPAREN, // )
  DASH,
  END
};

const char *kind_to_string(TokenType kind);
