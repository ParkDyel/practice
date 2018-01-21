#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

nptr initTreeNode(int data){
  nptr nodeBusket=(nptr)malloc(sizeof(nptr));
  nodeBusket->value=data;
  nodeBusket->left=NULL;
  nodeBusket->right=NULL;

  return nodeBusket;
}

void setData(nptr ptr, int data){
  ptr->value=data;
}
int getData(nptr ptr){
  if(ptr != NULL){
    return ptr->value;
  } else {
    fprintf(stdout, "error:Incorrect Access:dosen\'t exist\n");
    return NULL;
  }
}

nptr setLeftNode(nptr parent, int data){
  printf("start to allocate %d\n", parent);
  nptr nodeBusket = initTreeNode(data);
  parent->left=nodeBusket;
  return nodeBusket;
}

nptr getLeftNode(nptr ptr){
  return ptr->left;
}

nptr setRightNode(nptr parent, int data){
  nptr nodeBusket = initTreeNode(data);
  parent->right=nodeBusket; //first fix:not allocate right value.
  return nodeBusket;
}

nptr getRightNode(nptr ptr){
  return ptr->right;
}

int deleteNode(nptr ptr, char option){
  if(ptr->left == NULL && ptr->right == NULL){
    printf("clear ptr: %d\n", ptr);
    free(ptr);
  } else if(option == 'F'){
    deleteNode(ptr->left, 'F');
    deleteNode(ptr->right, 'F');
  } else {
    printf("this node have child");
    return -1;
  }
}

void deleteChildNode(nptr ptr){
  if (ptr->left == NULL && ptr->right == NULL){
    printf("noting to do");
    return;
  }
  deleteNode(ptr->left, 'F');
  ptr->left = NULL;
  deleteNode(ptr->right, 'F');
  ptr->right = NULL;
}

void deleteTree(nptr ptr){
  deleteChildNode(ptr);
}