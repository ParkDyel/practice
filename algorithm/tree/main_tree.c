#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
  tree* firstTree = (tree*)malloc(sizeof(tree));
  init(firstTree, 7);

  setLeftNode(tree->root, 15);
  setRightNode(tree->root, 2);

  fprintf(stdout, 'root:%d \t left:%d \t left:%d \n', getData(tree->root), getData(tree->root->left), getData(tree->root->right))
}