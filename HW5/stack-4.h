/*
320112
problem_5.3
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct stack
{
  char s[30];
  struct stack *next;
};

struct top
{
  int num;
  struct stack *top;
};
//function prototypes
void push(struct top *top, char str[30]);
void pop (struct top *top, char s[30]);
void create_stack(struct top *s, char str[1000]);
void display(struct top *top);
void compare(struct top *top, char *s);


#endif
