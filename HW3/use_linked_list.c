/*
320112
problem_4.1
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

//function prototypes


int main() {
  char line[100];
  struct list *my_list=NULL;
  //while loop to contionusly run
  while (1) {
    char n;
    int value;
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%c", &n);
    //switch for cases depending on entered letter
    switch (n) {
      case 'b':
      fgets(line, sizeof(line), stdin);
      sscanf(line, "%d", &value);
      my_list = push_front(my_list, value);
      break;
      case 'a':
      fgets(line, sizeof(line), stdin);
      sscanf(line, "%d", &value);
      my_list=push_back(my_list, value);
      break;
      case 'r':
      my_list = pop(my_list);
      break;
      case 'p':
      print_elements(my_list);
      break;
      case 'q':
      dispose_list(my_list);
      return 1;
    }
  }
  return 0;
}
