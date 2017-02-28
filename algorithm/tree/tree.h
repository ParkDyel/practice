#ifndef TREE_H_
#define TREE_H_

typedef struct _node{
  int value;
  struct _node* left;
  struct _node* right;
} node;

typedef node* nptr;

typedef struct _tree{
  nptr root;
} tree;

void init(tree* tptr,int data);
void setData(node* nptr, int data);
int getData(node* nptr);
void setLeftNode(node* nptr, int data);
node* getLeftNode(node* nptr);
void setRightNode(node* nptr, int data);
node* getRightNode(node* nptr);
void deleteNode(node* nptr, char option);
void deleteChildNode(node* nptr);
void deleteTree(node* nptr);

#endif /* TREE_H_ */