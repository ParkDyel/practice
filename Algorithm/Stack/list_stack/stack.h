#ifndef STACK_H_
#define STACK_H_

typedef struct _node{
  int value;
  struct _node* next;
} node;

typedef node* nptr;

typedef struct _stack{
  int count;
  nptr top;
} stack;

void init(stack* sptr);
void push(stack* sptr, int value);
int pop(stack* sptr);
int getTop(stack* sptr);
int getCount(stack* sptr);
void free_stack(stack* sptr);

#endif /* STACK_H_ */