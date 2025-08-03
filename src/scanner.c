#include "scanner.h"
#include "literal.h"
#include "token.h"
#include "token_type.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TokenList scan(char *source) {
  Scanner scanner = {.source = source, .start = 0, .current = 0, .line = 1};

  int capacity = 2;
  int size = 0;

  TokenList tokens;
  tokens.data = malloc(capacity * sizeof(Token));

  while (!is_at_end(&scanner)) {
    if (size == capacity) {
      capacity *= 2;
      tokens.data = realloc(tokens.data, capacity * sizeof(Token));
    }

    Token token;
    scanner.start = scanner.current;
    char c = advance(&scanner);

    switch (c) {
    case '(':
      token = make_token(LEFT_PAREN, "(", no_literal(), scanner.line);
      tokens.data[size++] = token;
      break;
    case ')':
      token = make_token(RIGHT_PAREN, ")", no_literal(), scanner.line);
      tokens.data[size++] = token;
      break;
    case '{':
      token = make_token(LEFT_BRACE, "{", no_literal(), scanner.line);
      tokens.data[size++] = token;
      break;
    case '}':
      token = make_token(RIGHT_BRACE, "}", no_literal(), scanner.line);
      tokens.data[size++] = token;
      break;
    case ',':
      token = make_token(COMMA, ",", no_literal(), scanner.line);
      tokens.data[size++] = token;
      break;
    case '.':
      token = make_token(DOT, ".", no_literal(), scanner.line);
      tokens.data[size++] = token;
      break;
    case '-':
      token = make_token(MINUS, "-", no_literal(), scanner.line);
      tokens.data[size++] = token;
      break;
    case '+':
      token = make_token(PLUS, "+", no_literal(), scanner.line);
      tokens.data[size++] = token;
      break;
    case ';':
      token = make_token(SEMICOLON, ";", no_literal(), scanner.line);
      tokens.data[size++] = token;
      break;
    case '*':
      token = make_token(STAR, "*", no_literal(), scanner.line);
      tokens.data[size++] = token;
      break;
    case '!':
      if (match(&scanner, '=')) {
        token = make_token(BANG_EQUAL, "!=", no_literal(), scanner.line);
        tokens.data[size++] = token;
      } else {
        token = make_token(BANG, "!", no_literal(), scanner.line);
        tokens.data[size++] = token;
      }
      break;
    case '=':
      if (match(&scanner, '=')) {
        token = make_token(EQUAL_EQUAL, "==", no_literal(), scanner.line);
        tokens.data[size++] = token;
      } else {
        token = make_token(EQUAL, "=", no_literal(), scanner.line);
        tokens.data[size++] = token;
      }
      break;
    case '<':
      if (match(&scanner, '=')) {
        token = make_token(LESS_EQUAL, "<=", no_literal(), scanner.line);
        tokens.data[size++] = token;
      } else {
        token = make_token(LESS, "<", no_literal(), scanner.line);
        tokens.data[size++] = token;
      }
      break;
    case '>':
      if (match(&scanner, '=')) {
        token = make_token(GREATER_EQUAL, ">=", no_literal(), scanner.line);
        tokens.data[size++] = token;
      } else {
        token = make_token(GREATER, ">", no_literal(), scanner.line);
        tokens.data[size++] = token;
      }
      break;
    case '/':
      if (match(&scanner, '/')) {
        while (peek(&scanner) != '\n' && !is_at_end(&scanner))
          advance(&scanner);
      } else {
        token = make_token(SLASH, "/", no_literal(), scanner.line);
        tokens.data[size++] = token;
      }
      break;
    case ' ':
    case '\r':
    case '\t':
      break;
    case '\n':
      scanner.line++;
      break;
    case '"':
      char *value = string(&scanner);
      Literal lit = string_literal(value);
      token = make_token(STRING, value, lit, scanner.line);
      tokens.data[size++] = token;
      break;
    default:
      if (is_digit(c)) {
        char *num_str = number(&scanner);
        Literal lit = number_literal(num_str);
        token = make_token(NUMBER, num_str, lit, scanner.line);
        tokens.data[size++] = token;
      } else if (is_alpha(c)) {
        char *value = identifier(&scanner);
		printf("is alpha returns: %s",value);
        //        Literal lit = identifiers_literal(value);
        // Problem WHAT?, I need to get the identifier TOKENS
        //        token = make_token(WHAT, value, lit, scanner.line);
      } else {
        printf("Unexpected character: %c", c);
      }
      break;
    }
  }

  tokens.size = size;
  tokens.capacity = capacity;

  return tokens;
}
char *string(Scanner *scanner) {
  while (peek(scanner) != '"' && !is_at_end(scanner)) {
    if (peek(scanner) == '\n') {
      scanner->line++;
    }
    advance(scanner);
  }

  if (is_at_end(scanner)) {
    printf("Error: Unterminated string in line: %d", scanner->line);
  }

  advance(scanner);
  int length = scanner->current - scanner->start - 2; // exclude surroundings

  // Allocate memory for the string
  char *value = malloc(length + 1);
  if (value == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  strncpy(value, scanner->source + scanner->start + 1, length);
  return value;
}

char *number(Scanner *scanner) {
  while (is_digit(peek(scanner))) {
    advance(scanner);
  }

  if (peek(scanner) == '.' && is_digit(peek_next(scanner))) {
    advance(scanner);

    while (is_digit(peek(scanner))) {
      advance(scanner);
    }
  }
  int length = scanner->current - scanner->start; // exclude surroundings

  // Allocate memory for the string
  char *num_str = malloc(length + 1);
  if (num_str == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  strncpy(num_str, scanner->source + scanner->start, length);
  return num_str;
}

char *identifier(Scanner *scanner) {
  while (is_alpha_numeric(peek(scanner))) {
    advance(scanner);
  }

  int length = scanner->current - scanner->start;

  // Allocate memory for the string
  char *value = malloc(length);
  if (value == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  strncpy(value, scanner->source + scanner->start, length);
  return value;
}

char peek(Scanner *scanner) {
  if (is_at_end(scanner)) {
    return '\0';
  }
  return scanner->source[scanner->current];
}

char peek_next(Scanner *scanner) {
  char next_char = scanner->source[scanner->current + 1];
  if (next_char == '\0') {
    return '\0';
  }
  return next_char;
}

char advance(Scanner *scanner) {
  char current_char = scanner->source[scanner->current];
  scanner->current++;
  return current_char;
}

bool is_at_end(Scanner *scanner) {
  char current_char = scanner->source[scanner->current];
  return current_char == '\0';
}

bool is_digit(char current_char) {
  return current_char >= '0' && current_char <= '9';
}

bool is_alpha(char current_char) {
  return (current_char >= 'a' && current_char <= 'z') ||
         (current_char >= 'A' && current_char <= 'Z') || current_char == '_';
}

bool is_alpha_numeric(char current_char) {
  return is_alpha(current_char) || is_digit(current_char);
}

bool match(Scanner *scanner, char expected) {
  if (is_at_end(scanner)) {
    return false;
  }

  char current_char = scanner->source[scanner->current];
  if (current_char != expected)
    return false;

  scanner->current++;
  return true;
}
