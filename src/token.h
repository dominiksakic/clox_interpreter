#ifndef TOKEN_H
#define TOKEN_H

#include "token_type.h"
#include "literal.h"

typedef struct {
  TokenType type;
  char* lexeme;
  Literal literal;
  int line;
} Token;

void print_token(Token token);

Token make_token(TokenType type, char* lexeme, Literal literal, int line);

#endif



