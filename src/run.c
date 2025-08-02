#include "run.h"
#include "scanner.h"
#include "token.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 1024

void run(char *source) {
  TokenList tokens = scan(source);
  for (int i = 0; i < tokens.size; i++) {
    int defined_enums = 39;
    if (tokens.data[i].type > defined_enums) {
      printf("\n");
      break;
    }
    print_token(tokens.data[i]);
  }
  free(tokens.data);
}

void runFile(char *path) {
  char buffer[CHUNK_SIZE];
  FILE *fptr = fopen(path, "r");
  if (fptr == NULL) {
    perror("Error reading file.");
    return;
  }
  while (fgets(buffer, CHUNK_SIZE, fptr) != NULL) {
    run(buffer);
  }
  fclose(fptr);
}

void runPrompt() {
  bool read_input = true;
  char buffer[CHUNK_SIZE];
  while (read_input) {
    printf(">");
    if (fgets(buffer, CHUNK_SIZE, stdin) == NULL) {
      printf("Error or EOF.\n");
      break;
    }
    run(buffer);
  }
}
