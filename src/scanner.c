#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "token.h" 

TokenList scanner(char* source){
  int capacity = 2; 
  int size = 0;
  TokenList tokens;
  tokens.data = malloc(capacity * sizeof(Token));

  for(int i = 0; i < 2; i++){
    if(size == capacity){
      capacity *= 2;
      tokens.data = realloc(tokens.data, capacity * sizeof(Token));
    }
    Token token = make_token(SLASH, "/", no_literal(), 1);
    tokens.data[size++] = token;
  }

  tokens.size = size;
  tokens.capacity = capacity;

 return tokens;
}
