/*
320112
problem_2.1
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *myArray = NULL; //pointer to integer
    int aSize; //Number of elements
    printf("Enter total number of elements.\n ");
    scanf("%d",&aSize); //Get input for size of Array
    myArray = (float *)malloc(aSize * sizeof(float));
    //Check memory validity
    if(myArray == NULL)
    {
      return 1;
    }
 //Loop to add elemts to Array
  for (int i = 0; i < aSize; i++)
  {
    float x;
    printf("Enter elements\n ");
    scanf("%f",&x); //Get inputs for elements of the array
    myArray[i] = x;
  }

do {
  int z;
  int *ptr = &myArray[z++];
  if (&ptr < 0) {
    int x = ptr - &myArray[0];
    printf("Before the first negative value: %d elements\n", x);
    break;
  }
} while(1);

 free(myArray); // free allocated memory

 return 0;
}
