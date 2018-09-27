/*
320112
problem_6.5
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
  //init
  FILE **fptr;
  FILE *output;
  char line[100];
  int flen=0;
  int x =0;
  int flag=0;
  char name[20];
  char buffer[64];

  memset(buffer, '\0', 64);
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &flen);

  fptr=(FILE**)malloc(sizeof(FILE)*flen);
  output=fopen("output.txt", "w");

  for(int i=0;i<flen;i++){
    fgets(name, 20, stdin);
    name[strlen(name)-1]='\0';
    fptr[i]=fopen(name, "r");
    if(fptr[i]==NULL)
    {
      printf("Error on %d file ", i+1);
      exit(1);
    }
  }

  int j=0;

  while(x!=flen)
  {
    flag=0;
    memset(buffer, '\0', 64);

    while(fread(buffer, 64, 1,fptr[x])==0){
      fwrite(buffer,1, 64, output);
      fprintf(output,"\r\n");
      printf("%s\n", buffer);
      memset(buffer, '\0', 64);
      x++;
      flag=1;
      if(x==flen){
        break;
        j=1;
      }
    }
    if(flag==1){
      continue;
    }
    while(j==0)
    {
      fwrite(buffer, 1, 64, output);
      printf("%s\n", buffer);
    }
  }
  for(int i=0;i<flen;i++){
  fclose(fptr[i]);
}
  free(fptr);

  fclose(output);


  return 0;
}
