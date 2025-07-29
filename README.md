# clox_interpreter

source: https://craftinginterpreters.com/scanning.html

- Goal: use the language design from crafting interpreters, but working from my own skills.

- Dataflow:

1.  read data source char\*
    SCAN
2.  make tokens and store them in a struct of TokenList
    2.1 convert into TokenList struct w/ Token*, size, and capacity
    2.2 Token is a struct w/ enum type, char*, struct literal, and a line
    2.3 Literal is a struct w/ a enum type, union of double or char\*

- First hurdle:
  - 1. create program that can print out txt file. (CLEAR, learned about c program structure of header files, makefile)
  - 2. print out txt that the user insert into cmd. (CLEAR)

Common mistakes: trying to assign a char to a char\*; loosing sight of what I used where, because there is so many files: header, c, and then trying to make everything modular... .

- Second hurdle:

  - How do I create objects?
  - How can I save a vague type to the same memory address? Like how can one MEM address hold a number or a string?

Common mistakes: loosing track of all the structs I have to create, and missing the includes.

Common mistake: again trying to assign a char to a char\*; Circular include; using '' instead "".

- Third hurdle:
  - How do I create a array? Goal is a array of addresses pointing to struts/tokens.
  - printing each token one by one in the run function.
