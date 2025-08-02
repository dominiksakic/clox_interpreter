// literal.c
#include "literal.h"

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
