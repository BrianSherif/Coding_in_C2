/*
320112
problem_1.3
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/


#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned char n;

    scanf("%c", &n);
    //print decimal representation
    printf("The decimal representation is: %d\n", n);

    //print backward in binary and return
    printf("The backwards binary representation is: ");

    for(int i = 0; i < 7; i++){
        (n & 1 << i) ? printf("1") : printf("0");
    }
    printf("\n");
    return 0;
}
