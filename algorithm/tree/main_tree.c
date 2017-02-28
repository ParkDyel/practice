#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
  
nptr root=initTreeNode(7);
printf("%d\n",root->value);

  nptr node1 = setLeftNode(root, 15);
  nptr node2 = setRightNode(root, 2);
  nptr node3 = setLeftNode(node1, 7);
  nptr node4 = setLeftNode(node2, 13);
  nptr node5 = setRightNode(node2, 13);

  // printf("%d\n", getData(root->left));
  // printf("%d\n", getData(root->left->left));
  // printf("%d\n", getData(root->left->left->left));
  // printf("%d\n", getData(root->right));
  // printf("%d\n", getData(root->right->right));
  printf("root\t\tnode1\t\tnode2\t\tnode3\t\tnode4\t\tnode5\t\t\n");
  printf("%d\t", root);
  printf("%d\t", node1);
  printf("%d\t", node2);
  printf("%d\t", node3);
  printf("%d\t", node4);
  printf("%d\t\n", node5);

  deleteChildNode(node2);
  printf("%d\n", getData(node2));
  printf("%d\n", getRightNode(node2));
  printf("%d\t\n", node5); // he is alive!!!
  printf("%d\n", getData(node5));
}