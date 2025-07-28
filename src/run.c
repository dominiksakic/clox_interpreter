#include <stdio.h>
#include <stdbool.h>
#include "token.h"
#include "run.h"

#define CHUNK_SIZE 1024

void run(char* source){
  for(int i = 0; source[i] != '\0'; i++){
    char c = source[i];
    if (c == '\n') continue;
    if (c == '/'){

      Token token = make_token(SLASH, "/", no_literal(), 1);
      print_token(token);
      
    }
  }
}

void runFile(char* path){
  char buffer[CHUNK_SIZE];
  FILE *fptr = fopen(path, "r");
  if(fptr == NULL){
    perror("Error reading file.");
    return;
  }
  while(fgets(buffer, CHUNK_SIZE, fptr) != NULL){
    run(buffer);
  }
  fclose(fptr);
}

void runPrompt(){
  bool read_input = true;
  char buffer[CHUNK_SIZE];
  while(read_input){
    printf(">");
    if (fgets(buffer, CHUNK_SIZE, stdin) == NULL){
      printf("Error or EOF.\n");
      break;
    }
    run(buffer);
  }
}
