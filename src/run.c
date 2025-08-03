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
  FILE *fptr = fopen(path, "r");
  if (fptr == NULL) {
    perror("Error reading file.");
    return;
  }
  // Read the whole file and rewind to beginning.
  fseek(fptr, 0, SEEK_END);
  long file_size = ftell(fptr);
  rewind(fptr);

  char *buffer = malloc(file_size + 1);
  if (buffer == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    fclose(fptr);
    return;
  }

  size_t bytes_read = fread(buffer, 1, file_size, fptr);
  buffer[bytes_read] = '\0'; // Null-terminate

  fclose(fptr);

  run(buffer);
  free(buffer);
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
