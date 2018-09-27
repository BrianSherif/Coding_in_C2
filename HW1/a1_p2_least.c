/*
320112
problem_1.2
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#include <stdio.h>

#define LSB(X)
 if (x & 1) {
  printf("The least significant bit is: 1");
  }
  else {
  printf("The least significant bit is: 0");
}



int main()
{
  char A;
  scanf("%c", &A);
  printf("The decimal representation is: %d\n", A);
  LSB(A);

  return 0;
}
