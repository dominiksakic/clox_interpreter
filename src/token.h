#ifndef TOKEN_H
#define TOKEN_H

#include "literal.h"
#include "token_type.h"

typedef struct {
  TokenType type;
  char *lexeme;
  Literal literal;
  int line;
} Token;

typedef struct {
  Token *data;
  int size;
  int capacity;
} TokenList;

void print_token(Token token);

Token make_token(TokenType type, char *lexeme, Literal literal, int line);

#endif
