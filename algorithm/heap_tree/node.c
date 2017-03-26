#include <stdio.h>
#include <stdlib.h>
#include "node.h"

nptr initNode(int data){
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

int deleteNode(nptr ptr, char option){
  printf("clear ptr: %d\n", ptr);
  free(ptr);
}