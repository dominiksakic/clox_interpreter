#include "token.h"
#include <stdio.h>

void print_token(Token token) {
  printf("Type: %d, Lexeme: %s, ", token.type, token.lexeme);
  switch (token.literal.type) {
  case LITERAL_NUMBER:
    printf("Literal: %f", token.literal.as.number);
    break;
  case LITERAL_STRING:
    printf("Literal: %s", token.literal.as.string);
    break;
  default:
    printf("Literal: (none)");
  }
  printf(", Line: %d\n", token.line);
}

Token make_token(TokenType type, char *lexeme, Literal literal, int line) {
  Token token;
  token.type = type;
  token.lexeme = lexeme;
  token.literal = literal;
  token.line = line;
  return token;
}
