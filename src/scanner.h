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

char peek(Scanner* scanner);

bool is_at_end(Scanner* scanner);

bool match(Scanner* scanner, char expected);

TokenList scan(char* source);
#endif
