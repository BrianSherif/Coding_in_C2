/*
320112
problem_1.1
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#include <stdio.h>
/*
The following Macro was inspired from the following Stack overflow link
https://stackoverflow.com/questions/3982348/implement-generic-swap-macro-in-c
The Macro does the following:
1) it receives 2 inputs 'x' and 'y'
2) it also receives the input type. This input type is used to create a THIRD variables
3) This Third varaible is used to be able to move the value of the varaible from 1 variable to the other.
*/
#define SWAP(x, y, type) { typeof(type) z = x; x = y; y = z; };
int main() {
  // creating 4 variables to take in an assigment from keyboard
  int a;
  int b;
  double c;
  double d;
  //receiving all inputs from keyboard
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%lf", &c);
  scanf("%lf", &d);
  //implementing SWAP
  SWAP (a, b, int);
  SWAP (c, d, double);
  // Printing the result after swapping
  printf("After swapping:\n%d\n%d\n%.6lf\n%.6lf\n", a, b, c, d); // note the order of the printed variables
  //to give the floats a precision of 6 I have used basic formatting.
  return 0;
}
