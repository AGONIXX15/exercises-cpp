#pragma once

enum class TokenKind { KEY, SEMICOLON, LIST, STRING, INT_NUMBER, FLOAT_NUMBER };

const char *kind_to_string(TokenKind kind);
