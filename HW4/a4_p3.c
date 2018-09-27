/*
320112
problem_4.3
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int my_compare_asc(const void *va, const void *vb);
int my_compare_desc(const void *va, const void *vb);
void asc(int *arr, int n);
void desc(int *arr, int n);
void drop(int *arr, int n);

int main(){
  int n;
  char ch;
  scanf("%d", &n);
  int *arr = malloc(n * sizeof(int));
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
    getchar();
  }
  arr[n] = '\0';

  //array of function pointers
  void (*fptr[3]) (int*, int) = {asc, desc, drop};

  //infinite while loop
  while(1){
    //read character
    scanf("%c", &ch);
    getchar();
    //change them to a location int the fucntion pointer array
    int x;
    if (ch == 'a') {
      x = 0;
    }
    if (ch == 'd') {
      x = 1;
    }
    if (ch == 'e') {
      x = 2;
    }
    fptr[x](arr, n);
  }
  return 0;
}

//acending order
int incr(const void *a, const void *b)
{
  const int *ia = (const int *)a;
  const int *ib = (const int *)b;
  return *ia  - *ib;// returns the difference so positive or negative
}

int decr(const void *a, const void *b)
{
  const int *ia = (const int *)a;
  const int *ib = (const int *)b;
  return *ib  - *ia;// returns the difference so positive or negative
}

//sort acending order
void asc(int *arr, int n){
  int i;
  qsort(arr, n, sizeof(int), incr);
  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

//sort decending order
void desc(int *arr, int n){
  int i;
  qsort(arr, n, sizeof(int), decr);
  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

//quits
void drop(int *arr, int n){
  exit(1);
}
