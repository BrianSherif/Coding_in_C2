/*
320112
problem_4.2
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//function prototypes
void a(char *str);
void b(char *str);
void c(char *str);
void d(char *str);

int main(){
    //init
    char str[200];
    //read string
    fgets(str, 200, stdin);
    str[strlen(str) - 1] = '\0';
    //array of function pointers, to make life easier; I used characters as function names.
    void (*fptr[4]) (char*) = {a, b, c, d};
    //infinite while loop
    int x;
    while(1){
        //read character
        scanf("%d", &x);
        x = x - 1; //subtracts one to read array from start
        fptr[x](str);
    }
    return 0;
}

//makes input string UPPERCASE
void a(char *str){
    char temp;
    while((*str) != '\0'){
        temp = toupper(*str);
        printf("%c", temp);
        str++;
    }
    printf("\n");
}

//makes input string lowercase
void b(char *str){
    char temp;
    while(*str != '\0'){
        temp = tolower(*str);
        printf("%c", temp);
        str++;
    }
    printf("\n");
}

//Switch UPPERCASE to lowercase and lowercase to UPPERCASE
void c(char *str){
    char temp;
    while(*str != '\0'){
        //upper case to lower case
        if(*str >= 65 && *str <=90){//ASCII codes for UPPERCASE
            temp = tolower(*str); //function to switch to lowercase
            printf("%c", temp);
            str++;
        }
        //lower case to upper case
        else if(*str >= 90 && *str <= 122){ //ASCII codes for lowercase
            temp = toupper(*str); //function to switch to UPPERCASE
            printf("%c", temp);
            str++;
        }
        else{
            printf("%c", *str);
            str++;
        }
    }
    printf("\n");

}
//Quit the program
void d(char *str){
  exit (1);
}
