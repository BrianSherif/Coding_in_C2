/*
320112
problem_4.4
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct person{
  char name[30];
  int age;
};
//function prototypes
int compare_age(struct person va, struct person vb);
int compare_name(struct person va, struct person vb);
void bubblesort(struct person *arr, int n, int (*compare)(struct person a, struct person b));
void printarray(struct person *arr, int n);

int main(){
  //init
  int n, i;

  //no. of persons 
  scanf("%d", &n);
  getchar();

  //dynamically allocate and read values in array
  struct person *arr = (struct person *) malloc(sizeof(struct person)* n);
  for(i = 0; i < n; i++){
    fgets(arr[i].name, sizeof(arr[i].name), stdin);
    arr[i].name[strlen(arr[i].name) - 1] = '\0';
    scanf("%d", &arr[i].age);
    getchar();
  }

  //sort, print and return
  int (*ptr[2])(struct person a, struct person b) = {compare_name, compare_age};
  bubblesort(arr, n, ptr[0]);
  printarray(arr, n);
  bubblesort(arr, n, ptr[1]);
  printarray(arr, n);
  free(arr);
  return 0;
}

//compare ages of persons
int compare_age(struct person va, struct person vb){
  if(va.age > vb.age){
    return 1;
  }
  else if(va.age < vb.age){
    return -1;
  }
  else if(strcmp(va.name, vb.name) > 0){
    return 1;
  }
  else if(strcmp(va.name, vb.name) < 0){
    return -1;
  }
  return 0;

}

//compare names of persons
int compare_name(struct person va, struct person vb){
  if(strcmp(va.name, vb.name) > 0){
    return 1;
  }
  else if(strcmp(va.name, vb.name) < 0){
    return -1;
  }
  else if(va.age > vb.age){
    return 1;
  }
  else if(va.age < vb.age){
    return -1;
  }
  return 0;

}

//implement bubble sort
void bubblesort(struct person *arr, int n, int (*compare)(struct person a, struct person b)){
  int i;
  int swap;
  struct person temp;
  do{
    swap = 0;
    for(i = 1; i < n; i++){
      if(compare(arr[i-1], arr[i]) > 0){
        temp = arr[i-1];
        arr[i-1] = arr[i];
        arr[i] = temp;
        swap = 1;
      }
    }
  }while(swap == 1);
}

//prints array
void printarray(struct person *arr, int n){
  int i;
  for(i = 0; i < n; i++){
    printf("{%s, %d}; ", arr[i].name, arr[i].age);
  }
  printf("\n");
}
