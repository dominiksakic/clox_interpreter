#include "token_type.h"
#include "literal.h"

typedef struct {
  TokenType type;
  char* lexeme;
  Literal literal;
  int line;
} Token;

void print_token(Token token);
