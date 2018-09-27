/*
320112
problem_1.7
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

void set3bits(unsigned int n, int p1, int p2, int p3);

int main(){
    unsigned char a;
    int b, c, d;

    //read from keyboard
    scanf("%c", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    //print the code for the first element
    printf("The decimal representation is: %d\n", a);
    //print in binary
    printf("The binary representation is: ");
    for(int i = 7; i >= 0; i--){
        if(a & 1 << i){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n");

    printf("After setting the bits: ");
    set3bits(a, b, c, d);
    printf("\n");

    return 0;
}

void set3bits(unsigned int n, int p1, int p2, int p3){
    int i;
    for(i = 7; i >= 0; i--){

        if (i == p1) printf("1");


        else if(i == p2){
            if(n & 1 << i) printf("0");
            else printf("1");
        }


        else{
            if(n & 1 << i) printf("1");

            else printf("0");
        }
    }
}
