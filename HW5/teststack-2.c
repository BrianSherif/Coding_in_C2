#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
  //init
  char ch;
  int n;
  struct stack st;
  //setting counter to 1
  st.counter = 1;
  while (1) {
    //endless loop that uses cases based on inputed letter
    scanf("%c", &ch);
    switch (ch) {
      case 's':
      scanf("%d", &n);
      st = push (st, n);
      break;
      case 'p':
      st = pop (st);
      break;
      case 'e':
      st = empty (st);
      printf("\n");
      break;
      case 'q':
      printf("Quit\n" );
      exit (1);
      break;
    }
  }
  return 0;

}
