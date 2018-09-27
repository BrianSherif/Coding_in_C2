/*
320112
problem_5.3
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


int main()
{
  char input[30]; // input (max characters are 30)
  struct top top; // initializing stack
  top.num=0;
  top.top=NULL;

  while(1)
  {
    fgets(input, 100, stdin);
    input[strlen(input)-1]='\0';

    if(strcmp(input, "exit")==0)
    break;

    create_stack(&top, input);
    compare(&top, input);
  }
  return 0;
}
