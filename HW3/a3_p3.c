/*
320112
problem_3.3
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
struct list* push_front(struct list *my_list, char info);
void print_list(struct list* my_list);
void print_list_backwards(struct list* my_list);
struct list* remove_element(struct list *my_list, char info);
void dispose_list(struct list* my_list);
//struct for doubly linked list
struct list{
  char info;
  struct list *next;
  struct list *prev;
};

int main(){
  struct list *my_list = NULL;
  char n;
  int x;

  do{
    scanf("%d", &x);
    getchar();
    switch(x){
      case 1:
      scanf("%c", &n);
      getchar();
      my_list = push_front(my_list, n);
      break;
      case 2:
      scanf("%c", &n);
      getchar();
      my_list = remove_element(my_list, n);
      break;
      case 3:
      print_list(my_list);
      break;
      case 4:
      print_list_backwards(my_list);
      break;
      case 5:
      dispose_list(my_list);
      return 0;
      break;
    }
  }while(1);
  return 0;
}


//Pushes input to the begining of my_list
struct list* push_front(struct list *my_list, char info) {
  struct list *newel;
  newel = malloc(sizeof(struct list));
  newel->info = info;
  newel->next = my_list;
  if(my_list != NULL){
    my_list->prev = newel;
  }
  newel->prev = NULL;
  return newel;
}

//pop value from my_list
struct list* remove_element(struct list *my_list, char info){
  int del = 0;
  struct list *cursor, *temp;
  cursor = my_list;
  while(cursor->info == info){
    del++;
    temp = cursor;
    cursor = cursor->next;
    if(cursor != NULL){
      cursor->prev = NULL;
    }
    else{
      return NULL;
    }
  }
  my_list = cursor;
  // To make my_list point to an element whose value isn't that of the one we want to remove.
  while(cursor->next != NULL){
    if((cursor->next)->info == info){
      del++;
      temp = cursor->next;
      cursor->next = temp->next;
      if(temp->next != NULL){
        (temp->next)->prev = cursor;
      }
    }
    else{
      cursor = cursor->next;
    }
  }
  if(del == 0){
    printf("The element is not in the list!\n");
  }
  return my_list;

}


//prints my_list
void print_list(struct list* my_list) {
  struct list *cursor;
  cursor = my_list;
  while (cursor != NULL){
    printf("%c ", cursor->info);
    cursor = cursor->next;
  }
  printf("\n");
}

//prints my_list in reverse
void print_list_backwards(struct list* my_list) {
  struct list *cursor;
  cursor = my_list;
  while (cursor->next != NULL){
    cursor = cursor->next;
  }
  while(cursor != NULL){
    printf("%c ", cursor->info);
    cursor = cursor->prev;
  }
  printf("\n");
}


//free memory taken by elements in my_list
void dispose_list(struct list* my_list){
  struct list *nextelem;
  while (my_list != NULL){
    nextelem = my_list->next;
    free(my_list);
    my_list = nextelem;
  }
}
