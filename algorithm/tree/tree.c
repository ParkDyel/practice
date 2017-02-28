#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void init(tree* tptr, int data){
  nptr* node=(nptr*)malloc(sizeof(nptr));
  node->value=data;
  tptr->root=node;
}

void setData(node* nptr, int data){
  nptr->value=data;
}
int getData(node* nptr){
  return nptr->value;
}

void setLeftNode(node* parent, int data){
  nptr* node=(nptr*)malloc(sizeof(nptr));
  node->value=data;
  parent->left = node;
}

node* getLeftNode(node* nptr){
  return nprt->left
}

void setRightNode(node* parent, int data){
  nptr* node=(nptr*)malloc(sizeof(nptr));
  node->value=data;
  parent->right = node;
}

node* getRightNode(node* nptr){
  return nprt->right
}

void deleteNode(node* nptr, char option){
  if(nptr->left == NULL && nptr->right == NULL){
    free(nptr);
  } else if(option == 'F'){
    deleteNode(nptr->left, 'F');
    deleteNode(nptr->right, 'F');
  } else {
    printf("this node have child")
    return -1;
  }
}

void deleteChildNode(node* nptr){
  if (nptr->left == NULL && nptr->right == NULL){
    printf("noting to do");
    return;
  }
  deleteNode(nptr->left, 'F');
  deleteNode(nptr->right, 'F');
  nptr->left = NULL;
  nptr->right = NULL;
}

void deleteTree(node* nptr){
  deleteChildNode(nptr);
}