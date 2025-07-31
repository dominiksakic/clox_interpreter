#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "scanner.h"
#include "token.h" 

TokenList scan(char* source){
  Scanner scanner = {
    .source = source,
    .start = 0,
    .current = 0,
    .line = 1
  };

  int capacity = 2; 
  int size = 0;

  TokenList tokens;
  tokens.data = malloc(capacity * sizeof(Token));
  
  while (!is_at_end(&scanner)){
    if(size == capacity){
      capacity *= 2;
      tokens.data = realloc(tokens.data, capacity * sizeof(Token));
    }

    char c = advance(&scanner);
    
    if(c =='\n'){
      scanner.line++;
      continue;
    }

    Token token;
    int line = scanner.line;

    switch(c){
      case '(' : 
        token = make_token(LEFT_PAREN, "(", no_literal(), line);
        break;
      case ')' : 
        token = make_token(RIGHT_PAREN, ")", no_literal(), line);
        break;
      case '{' : 
        token = make_token(LEFT_BRACE, "{", no_literal(), line);
        break;
      case '}' : 
        token = make_token(RIGHT_BRACE, "}", no_literal(), line);
        break;
      case ',' : 
        token = make_token(COMMA, ",", no_literal(), line);
        break;
      case '.' : 
        token = make_token(DOT, ".", no_literal(), line);
        break;
      case '-' : 
        token = make_token(MINUS, "-", no_literal(), line);
        break;
      case '+' : 
        token = make_token(PLUS, "+", no_literal(), line);
        break;
      case ';' : 
        token = make_token(SEMICOLON, ";", no_literal(), line);
        break;
      case '*' : 
        token = make_token(STAR, "*", no_literal(), line);
        break;
      default:
        printf("Unexpected character: %c", c);
        break;
    }
    tokens.data[size++] = token;
  }

  tokens.size = size;
  tokens.capacity = capacity;

 return tokens;
}

char advance(Scanner* scanner){
  char current_char = scanner->source[scanner->current];
  scanner->current++;
  return current_char;
}

bool is_at_end(Scanner* scanner){
  char current_char = scanner->source[scanner->current];
  return current_char == '\0';
}


