/*
320112
problem_5.2
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main()
{
  unsigned int data;
  struct stack st; // create stack
  init(&st); // intialize s

  scanf("%u", &data); // get data from user

  printf("The binary representation of %u is ", data);
  binary(&st, data); // call the function to convert
  display(&st); // print the stack values

  printf("\n");

  return 0;
}
