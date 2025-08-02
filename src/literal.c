// literal.c
#include "literal.h"
#include <stddef.h>
#include <stdlib.h>

Literal no_literal(){
  Literal lit;
  lit.type = LITERAL_NONE;
  return lit;
}

Literal string_literal(char* value){
  Literal lit;
  lit.type = LITERAL_STRING;
  lit.as.string = value;
  return lit;
}

Literal number_literal(char* num_str){
  Literal lit;
  lit.type = LITERAL_NUMBER;
  double value = strtod(num_str, NULL);
  lit.as.number= value;
  return lit;
}
