/*
320112
problem_5.3
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


void push(struct top *top, char str[30]) // put elements into stack
{
  struct stack *temp;
  temp=malloc(1*sizeof(struct stack));
  temp->next = NULL;
  strcpy(temp->s, str);

  if(top->num==0)
  {
    top->top=temp;
    top->num=1;
  }
  else
  {
    temp->next=top->top;
    top->top=temp;
    top->num++;
  }
}

void pop (struct top *top, char s[30]) // output info
{
  struct stack *temp;
  temp=top->top;

  temp=temp->next;
  strcpy(s,top->top->s);
  free(top->top);
  top->top=temp;
  top->num--;
}

//create the stack from inputed elements
void create_stack(struct top *s, char str[1000])
{
  char temp1[30];
  int i=0, j=0;
  while(1)
  {
    if(str[i]!=' ' && str[i]!='\0')
    {
      temp1[j]=str[i];
      j++;
    }
    else
    {
      temp1[j]='\0';
      push(s, temp1);
      j=0;
    }
    if(str[i]=='\0')
    {
      break;
    }
    i++;
  }
}

// print values
void display(struct top *top)
{
  struct stack *cursor;
  cursor=top->top;

  while(cursor!=NULL)
  {
    printf("%s\n ", cursor->s);

    cursor=cursor->next;
  }
}

void compare(struct top *top, char *s)
{
  char s2[1000];
  s2[0]='\0';
  char ret[30];
  int len;


  pop(top,ret);
  strcpy(s2, ret);

  while(top->top!=NULL)
  {
    len=strlen(s2);
    s2[len]=' ';
    s2[len+1]='\0';
    ret[0]='\0';
    pop(top,ret);
    strcat(s2, ret);
  }

  if(strcmp(s, s2)==0)
  printf("The sentence is palindromic by words!\n");

  else
  printf("The sentence is not palindromic by words!\n");

}
