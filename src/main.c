#include <stdio.h>
#include <stdbool.h>
#include "run.h"

#define CHUNK_SIZE 1024

int main(int argc, char *argv[]){
  char buffer[CHUNK_SIZE];
  bool read_input = true;

  if(argc > 2){
    printf("%s", "Usage: clox [script]");
    return 64;

    // Execute file
  } else if(argc == 2){
    FILE *fptr = fopen(argv[1], "r");
    if(fptr == NULL){
      perror("Error reading file.");
      return 1;
    }
    while(fgets(buffer, CHUNK_SIZE, fptr) != NULL){
      run(buffer);
    }
    fclose(fptr);

    // Enter RePL
  } else {
    while(read_input){
      printf(">");
      if (fgets(buffer, CHUNK_SIZE, stdin) == NULL){
        printf("Error or EOF.\n");
        break;
      }
      run(buffer);
    }
  }
  
  return 0;
}
