#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "token.h" 

void scanner(char* source){
  int capacity = 2; 
  int size = 0;
  int* array = malloc(capacity * sizeof(int));

  for(int i = 0; i < 6; i++){
    if(size == capacity){
      capacity *= 2;
      array = realloc(array, capacity * sizeof(int));
    }
    array[size++] = i * 10;
  }
  for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
  free(array);

 return;
}
