/*
320112
problem_1.3
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#define max(a, b, c) ((a > b ? a : b) > c ? (a > b ? a : b): c)
#define min(a, b, c) ((a < b ? a : b) < c ? (a < b ? a : b): c)
#define expr(a, b, c) (( min(a, b, c) + max(a, b, c))/2  )

int main(){

    double a, b, c;


    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);



    printf("The mid-range is: %.6lf\n", expr(a, b, c));
    return 0;
}
