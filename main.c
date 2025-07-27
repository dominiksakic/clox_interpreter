#include <stdio.h>

#define BUFFER_SIZE

int main(int argc, char *argv[]){
  if (argc > 2){
    printf("%s", "Usage: clox [script]");
    return 64;
  } else if (argc == 2){
    printf("%s", "Execute file");
    return 0;
  } else {
    printf("%s", "run RePL");
    return 0;
  }
  
  return 0;
}
