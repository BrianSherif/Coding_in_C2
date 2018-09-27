/*
320112
problem_2.3
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//function prototype of multiplication
void multiplication(int **matA, int **matB, int a, int b, int c);
int main()
{
  char line[1000];
  int x;
  int y;
  int z;
  int **matA;
  int **matB;
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &x);
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &y);
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &z);
  //allocation of rows
  matA = (int**) malloc(sizeof(int *)*x);
  matB = (int**) malloc(sizeof(int *)*y);
  for(int i=0;i<x;i++)
  //allocation of collumns for first Matrix
  { matA[i]=(int *)malloc(sizeof(int)*y);
    for(int j=0;j<y;j++)
    {
      fgets(line, sizeof(line), stdin);
      sscanf(line,"%d",&matA[i][j]);
    }
  }
  //allocation of collumns for second Matrix
  for(int i=0;i<y;i++)
  {
    matB[i]=(int *)malloc(sizeof(int)*z);
    for(int j=0;j<z;j++)
    {
      fgets(line, sizeof(line), stdin);
      sscanf(line,"%d",&matB[i][j]);
    }
  }
  printf("Matrix A:\n");
  for(int i=0;i<x;i++)
  {
    for(int j=0;j<y;j++)
    {
      printf("%d ",matA[i][j]);
    }
    printf("\n");
  }
  printf("Matrix B:\n");
  for(int i=0;i<y;i++)
  {
    for(int j=0;j<z;j++)
    {
      printf("%d ",matB[i][j]);
    }
    printf("\n");
  }
  printf("The multiplication result AxB:\n");
  multiplication(matA, matB, x, y, z);
  //free allocated memory
  free(matA);
  free(matB);
}

void multiplication(int **matA, int **matB, int a, int b, int c){
  int **multi;//pointer to a pointer
  multi = (int **)malloc(sizeof(int *)*a);//Result of multiplication is a 2d Array

  for(int i=0;i<a;i++){
    multi[i]=(int *)malloc(sizeof(int)*c);
    for(int j=0;j<c;j++){
      int d=0;
      for(int k=0;k<b;k++){
        d += matA[i][k]*matB[k][j];
      }
      multi[i][j]=d;
      //prints values
      printf("%d ",multi[i][j]);
    }
    printf("\n");
  }
}
