#ifndef TREE_H_
#define TREE_H_

typedef struct _node{
  int value;
  struct _node* left;
  struct _node* right;
} node;

typedef node* nptr;

nptr initTreeNode(int data);
void setData(nptr ptr, int data);
int getData(nptr ptr);
nptr setLeftNode(nptr parent, int data);
nptr getLeftNode(nptr ptr);
nptr setRightNode(nptr parent, int data);
nptr getRightNode(nptr ptr);
int deleteNode(nptr ptr, char option);
void deleteChildNode(nptr ptr);
void deleteTree(nptr nptr);

#endif /* TREE_H_ */