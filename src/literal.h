//literal.h
#ifndef LITERAL_H
#define LITERAL_H

typedef enum {
  LITERAL_NONE,
  LITERAL_NUMBER,
  LITERAL_STRING
} LiteralType;

typedef struct {
  LiteralType type;
  union {
    double number;
    char* string;
  } as;
} Literal;

// Function to returna no-lteral, to save tyyping.
Literal no_literal();

Literal string_literal(char* value);

#endif
