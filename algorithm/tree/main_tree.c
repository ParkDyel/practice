#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
  
nptr root=initTreeNode(7);
printf("%d\n",root->value);

  // printf("start to create node\n");
  nptr node1 = setLeftNode(root, 15);
  nptr node2 = setRightNode(root, 2);
  nptr node3 = setLeftNode(node1, 7);
  nptr node4 = setLeftNode(node2, 13);
  nptr node5 = setRightNode(node2, 13);
  // printf("finished to create node\n");

  // printf("%d\n", getData(root->left));
  // printf("%d\n", getData(root->left->left));
  // printf("%d\n", getData(root->left->left->left));
  // printf("%d\n", getData(root->right));
  // printf("%d\n", getData(root->right->right));
  printf("root\tnode1\tnode2\tnode3\tnode4\tnode5\t\n");
  printf("%d\t", root);
  printf("%d\t", node1);
  printf("%d\t", node2);
  printf("%d\t", node3);
  printf("%d\t", node4);
  printf("%d\t\n", node5);

  deleteChildNode(node2);
  printf("%d\t", node2->value);
  printf("%d\t\n", node5->value);

}