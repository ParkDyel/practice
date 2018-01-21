#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"

BinTree* createBinTree(BinTreeNode rootNode){
  BinTree *pReturn = NULL;
  pReturn = (BinTree *)malloc(sizeof(BinTree));
  if(pReturn != NULL){
    pReturn->pRootNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    if(pReturn->pRootNode != NULL){
      *(pReturn->pRootNode) = rootNode;
      pReturn->pRootNode->pLeftChild = NULL;
      pReturn->pRootNode->pRightChild = NULL;
    } else {
      printf("Error:Memory Allocate was failed. createBinTree()(Node)\n");  
    }
  } else {
    printf("Error:Memory Allocate was failed. createBinTree()(Tree)\n");
  }

  return pReturn;
}

void deleteBinTree(BinTree* pBinTree){
  if(pBinTree != NULL){
    deleteBinTreeNode(pBinTree->pRootNode);
    free(pBinTree);
  }
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree);

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element){
  BinTreeNode* pReturn = NULL;
  if(pParentNode != NULL){

  } else {
    printf("Error:Pointer is NULL.insertLeftChildNodeBT()\n");
  }
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);

void deleteBinTreeNode(BinTreeNode* pNode){
  if(pNode != NULL){
    deleteBinTreeNode(pNode->pLeftChild);
    deleteBinTreeNode(pNode->pLeftChild);
    free(pNode);
  }
}