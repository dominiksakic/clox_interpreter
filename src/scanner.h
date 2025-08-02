#ifndef SCANNER_H
#define SCANNER_H
#include <stdbool.h>
#include "token.h"

typedef struct {
  char* source;
  int start;
  int current;
  int line;
} Scanner;

char advance(Scanner* scanner);

bool is_at_end(Scanner* scanner);

bool match(Scanner* scanner, char expected);

char peek(Scanner* scanner);

char peek_next(Scanner* scanner);

char* string(Scanner* scanner);

char* number(Scanner* scanner);

bool is_digit(char current_char);

TokenList scan(char* source);
#endif
