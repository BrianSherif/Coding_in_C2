/*
320112
problem_5.2
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct stack {
  unsigned int counter;
  int array[12];
};

void init (struct stack *st);
int isfull(struct stack *st);
int isempty(struct stack *st);
void push(struct stack *st,int data);
int pop(struct stack *st);
void binary(struct stack *st, unsigned int data);
void display(struct stack *st);

#endif // STACK_H_INCLUDED
