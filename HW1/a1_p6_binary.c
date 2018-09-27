/*
320112
problem_1.6
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    //init
    unsigned char x;
    //read int
    scanf("%c", &x);

    //print in binary and return
    printf("The decimal representation is: %d\n", x );
    printf("The binary representation is: ");
    for(int i = 7; i >= 0; i--){
        (x & 1 << i) ? printf("1") : printf("0");
    }
    printf("\n");
    return 0;
}
