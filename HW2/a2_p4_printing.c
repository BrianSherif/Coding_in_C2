/*
320112
problem_2.4
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//function prototypes
void readArray(int ***array, int a, int b, int c);
void print(int ***array, int x, int y, int z);
int main(){
  char line[100];
  //the three values of dimensions
  int x;
  int y;
  int z;
  int ***array;
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &x);
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &y);
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &z);
  //allocation of memory for rows, columns, and depth of array
  array = (int***)malloc(sizeof(int**)*x);
  for(int i = 0; i < x; i++){
    array[i] = (int**)malloc(sizeof(int*)*y);
    for(int j = 0; j < y; j++){
      array[i][j] = (int*)malloc(sizeof(int)*z);
    }
  }
  //call functions to allocate and create the array
  readArray(array, x, y, z);
  print(array, x, y, z);
  //free all allocated memory
  free(array);
  return 0;
}

void readArray(int ***array, int a, int b, int c){
  char line[100];
  for(int i = 0; i < a; i++){
    for(int j = 0; j < b; j++){
      for(int k = 0; k < c; k++){
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &array[i][j][k]);
        /*for loops cycle thru all three dimensions first storing the rows
        followed by the columns follewed by the depth of the array*/
      }
    }
  }
}
void print(int ***array, int x, int y, int z){
  //function created to print all the array
  for(int k = 0; k < z; k++){
    int a = k + 1;
    printf("Section %d:\n", a);
    for(int j = 0; j < y; j++){
      for(int i = 0; i < x; i++){
        printf("%d ", array[i][j][k]);
      }
      printf("\n");
    }
  }
}
