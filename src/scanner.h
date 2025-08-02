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

char* string(Scanner* scanner);

TokenList scan(char* source);
#endif
