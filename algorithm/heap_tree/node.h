#ifndef NODE_H_
#define NODE_H_

typedef struct _int_node{
  int value;
  struct _int_node* left;
  struct _int_node* right;
} int_node;

typedef int_node* nptr;

nptr initNode(int data);
void setData(nptr ptr, int data);
int getData(nptr ptr);
int deleteNode(nptr ptr, char option);

#endif /* NODE_H_ */