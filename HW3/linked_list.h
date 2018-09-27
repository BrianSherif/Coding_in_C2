/*
320112
problem_4.1
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/

struct list {
  int info;
  struct list *next;
};
struct list* push_front(struct list *my_list, int value);
struct list* push_back(struct list* my_list, int value);
void print_elements(struct list* my_list) ;
void dispose_list(struct list* my_list) ;
struct list* pop(struct list* my_list);
