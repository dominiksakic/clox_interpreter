#ifndef SCANNER_H
#define SCANNER_H
#include "token.h"
#include "token_type.h"
#include <stdbool.h>

typedef struct {
  char *source;
  int start;
  int current;
  int line;
} Scanner;

char advance(Scanner *scanner);

bool is_at_end(Scanner *scanner);

bool match(Scanner *scanner, char expected);

char peek(Scanner *scanner);

char peek_next(Scanner *scanner);

char *string(Scanner *scanner);

char *number(Scanner *scanner);

char *identifier(Scanner *scanner);

bool is_digit(char current_char);

bool is_alpha(char current_char);

bool is_alpha_numeric(char current_char);

TokenType get_keyword(char* parsed_word); 

TokenList scan(char *source);
#endif
