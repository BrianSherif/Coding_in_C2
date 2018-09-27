/*
320112
problem_2.1
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/


#include <stdio.h>
#include <stdlib.h>

//function prototypes
struct list* push_front(struct list *my_list, int value);
struct list* push_back(struct list* my_list, int value);
void print_elements(struct list* my_list) ;
void dispose_list(struct list* my_list) ;
struct list* pop(struct list* my_list);
struct list {
  int info;
  struct list *next;
};

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
//functions in full

struct list* push_front(struct list *my_list, int value)
{
  struct list *newel;
  newel = (struct list*) malloc(sizeof(struct list));
  if (newel == NULL) {
    printf("Error allocating memory\n");
  }
  newel->info = value;
  newel->next = my_list;
  return newel;
}


/* Like the previous one, but inserts at the end */
struct list* push_back(struct list* my_list, int value)
{
  struct list *cursor, *newel;

  cursor = my_list;
  newel = (struct list*) malloc(sizeof(struct list));
  if (newel == NULL) {
    printf("Error allocating memory\n");
    exit(1);
  }
  newel->info = value;
  newel->next = NULL;
  if (my_list == NULL)
  return newel;
  while (cursor->next != NULL)
  cursor = cursor->next;
  cursor->next = newel;
  return my_list;
}



void print_elements(struct list* my_list)
{
  while (my_list != NULL) {
    printf("%d ", my_list->info);
    my_list = my_list->next;
  }
  printf("\n");
}

void dispose_list(struct list* my_list)
{
  struct list *nextelem;
  while (my_list != NULL) {
    nextelem = my_list->next;
    free(my_list);
    my_list = nextelem;
  }
}


struct list* pop(struct list* my_list) {
    struct list* next = NULL;

    if (my_list == NULL) {
        return NULL;
    }

    next = (*my_list).next;
    free(my_list);
    my_list = next;
    return my_list;
}
