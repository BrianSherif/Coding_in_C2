#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//functions
struct stack push (struct stack st, int n)
{
  int i = st.counter;
    printf("Pushing");
  if (i == 13) {
    printf(" Stack Overflow\n");
    return st;
  }
  printf(" %d\n", n);
  st.array[i] = n;
  st.counter++;
  return st;
}


struct stack pop (struct stack st)
{
  int i = st.counter;
  printf("Popping ");
  int x = isempty (st);
  if (x == 1) {
    printf("Stack Underflow\n");
    return st;
  }
  printf("%d\n", st.array[i-1]);
  st.array[i-1] = 0;
  st.counter--;
  return st;
}


struct stack empty (struct stack st){
  printf("Emptying Stack ");
  for (int i = st.counter-1; i >= 1; i--) {
    printf("%d ", st.array[i]);
  }
  for (int i = 1; i <= 12; i++) {
    st.array[i] = 0;
  }
  st.counter = 0;
  return st;
}


int isempty (struct stack st){
  if (st.counter == 0) {
    return 1;
  }
  return 0;
}
