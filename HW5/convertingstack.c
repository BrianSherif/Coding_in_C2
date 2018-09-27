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


void init (struct stack *st) // initializenstack
{
  st->counter=0;
}



int isfull(struct stack *st) // check for full stack
{
  if(st->counter == 12)
  return true;
  else
  return false;
}



int isempty(struct stack *st) //check for empty stack
{
  if(st->counter == 0)
  return true;
  else
  return false;
}



void push(struct stack *st,int bin) // input data
{
  if (isfull(st)==true)
  {
    printf ("Pushing stack Overflow\n");
    return;
  }

  else // input element
  {
    st->array[st->counter] = bin;
    st->counter++;
  }
}




int pop(struct stack *st) // output data
{
  int num;
  if (isempty(st)==true)
  {
    return -1;
  }
  else // output element
  {
    num = st->array[(st->counter)-1];
    st->counter = st->counter - 1;
  }
  return(num);
}




void binary(struct stack *st, unsigned int bin) // get binary out a number
{
  int bin1;

  while(bin>=1)
  {
    bin1=(int)bin%2;
    push(st, bin1);
    bin=bin/2;
  }
}

void display(struct stack *st) // print stack
{
  int ret=pop(st);

  while(ret!=-1)
  {
    printf("%d", ret);
    ret=pop(st);
  }
  printf(".");
}
