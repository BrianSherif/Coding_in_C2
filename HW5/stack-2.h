#define STACK

struct stack push (struct stack st, int n);
struct stack pop (struct stack st);
struct stack empty (struct stack st);
int isempty (struct stack st);

struct stack {
  int counter;
  int array [12]; // Container
};
