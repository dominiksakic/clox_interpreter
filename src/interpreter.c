#include "interpreter.h"
#include "scanner.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024

void interpreter_init(Interpreter *interp) {
  interp->source_code = NULL;
  interp->has_error = false;
  interp->tokens.data = NULL;
  interp->tokens.size = 0;
}

void interpreter_free(Interpreter *interp) {
  free(interp->source_code);
  free(interp->tokens.data);
}

void interpreter_run_source(Interpreter *interp, const char *source) {
  free(interp->source_code); // free old if any
  interp->source_code = strdup(source);

  interp->tokens = scan(interp->source_code);

  int defined_enums = 39;
  for (int i = 0; i < interp->tokens.size; i++) {
    if (interp->tokens.data[i].type > defined_enums) {
      printf("\n");
      break;
    }
    print_token(interp->tokens.data[i]);
  }
}

void interpreter_run_file(Interpreter *interp, const char *path) {
  FILE *fptr = fopen(path, "r");
  if (!fptr) {
    perror("Error reading file");
    return;
  }

  fseek(fptr, 0, SEEK_END);
  long file_size = ftell(fptr);
  rewind(fptr);

  char *buffer = malloc(file_size + 1);
  if (!buffer) {
    fprintf(stderr, "Memory allocation failed\n");
    fclose(fptr);
    return;
  }

  size_t bytes_read = fread(buffer, 1, file_size, fptr);
  buffer[bytes_read] = '\0';
  fclose(fptr);

  interpreter_run_source(interp, buffer);
  free(buffer);
}

void interpreter_run_prompt(Interpreter *interp) {
  char buffer[CHUNK_SIZE];
  while (true) {
    printf(">");
    if (!fgets(buffer, CHUNK_SIZE, stdin)) {
      printf("Error or EOF.\n");
      break;
    }
    interpreter_run_source(interp, buffer);
		interp->has_error = false;
  }
}
