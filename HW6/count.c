/*
320112
problem_6.1
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>


int main() {
  //open file
  FILE *fp;
  fp = fopen("words.txt", "r");
  //check if file opened
  if( fp == NULL )  {
    perror ("Error opening file");
    //return error if not opened
    return(-1);
  }
  //set ch to a character in the file
  char ch = getc(fp);
  //use x as an indicator for wether the previous character was a separator
  int x = 0;
  int counter = 0;
  //while loop with if statments to compare two lines of charaters one behind the other.
  while ((ch = getc(fp)) != EOF) {
    if (x == 0) {
    if (ch == ' ' || ch == ',' || ch == '.' || ch == '?' || ch == '!' || ch == '\t' || ch == '\r' || ch == '\n'){
      counter++;
    }
    }
    if (ch == ' ' || ch == ',' || ch == '.' || ch == '?' || ch == '!' || ch == '\t' || ch == '\r' || ch == '\n'){
      x = 1;
    }
    else {
      x = 0;
    }
 }
 //printing and closing file
  printf("The file contains %d words.\n", counter);
  fclose(fp);
  return 0;
}
