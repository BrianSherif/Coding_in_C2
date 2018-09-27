/*
320112
problem_6.4
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct names {
  char name[20];
  int pos;
  struct names *next;
};
struct names *create_list(struct names *l, char *temp1, int pos);
struct names *create_list_from_File(FILE *fp);
int CheckUsername(char *s, struct names *l, int *i);
int CheckPassword(FILE *fp, struct names *l, char *passw, int *i);

int main()
{
  char usern[20];
  char passw[20];
  char file_name[20];
  FILE *fp;
  struct names *l=NULL;
  int i=0;

  fgets(file_name, 20, stdin);
  file_name[strlen(file_name)-1]='\0';

  fp=fopen(file_name, "r");

  if(fp==NULL)
  {
    printf("File not opened!\n");
    exit(1);
  }

  l = create_list_from_File(fp);


  while(strcmp(usern, "exit")!=0)
  {
    fgets(usern, 20, stdin);
    usern[strlen(usern)-1]='\0';

    if(CheckUsername(usern, l, &i)==1)
    {
      fgets(passw, 20, stdin);
      passw[strlen(passw)-1]='\0';

      if(CheckPassword(fp ,l, passw, &i)==1)
      printf("Access to user %s is granted.\n", usern);

      else
      printf("Access to user %s is denied.\n", usern);
    }
  }

  printf("Exiting ...\n");
  fclose(fp);
  return 0;
}


struct names *create_list(struct names *l, char *temp1, int pos) // creating of list data
{
  struct names *temp;
  temp=(struct names*)malloc(1*sizeof(struct names));
  strcpy(temp->name, temp1);
  temp->pos=pos;
  temp->next=l;

  return temp;

}

struct names * create_list_from_File(FILE *fp) // create list from file data
{
  char ch;
  int i = 0;
  int check = 0;
  int pos;
  struct names *l=NULL;

  char temp1[20];
  temp1[0]='\0';

  while(1)
  {
    if(check==1)
    break;

    while((ch=fgetc(fp))!='\n')
    {
      temp1[i]=ch;
      i++;
    }
    temp1[i]='\0';

    pos = ftell(fp); // pos where to read for password
    l=create_list(l,temp1, pos);

    while((ch=fgetc(fp))!='\n')
    {
      if(ch==EOF)
      {
        check=1;
        break;
      }
    }
    i=0;
  }
  return l;

}

int CheckUsername(char *s, struct names *l, int *i)
// check for username correctness
{
  int flag=0;
  struct names *cursor=l;
  *i=0;

  while (cursor!=NULL)
  {
    if(strcmp(cursor->name, s)==0)
    {
      flag=1;
      break;
    }
    cursor=cursor->next;
    (*i)++;
  }
  return flag;
}

int CheckPassword(FILE *fp, struct names *l, char *passw, int *i) // check for password
{
  struct names *cursor;

  cursor = l;
  int m = 0;
  int flag = 0;
  char c;
  char temp[20];

  while(m!=*i){
    cursor=cursor->next;
    m++;
  }

  m=0;

  fseek(fp, cursor->pos, SEEK_SET);

  while((c=fgetc(fp))!='\n')
  {
    if(c==EOF)
    break;
    temp[m]=c;
    m++;
  }

  temp[m]='\0';
  if(strcmp(passw, temp)==0){
    flag=1;
  }
  return flag;
}
