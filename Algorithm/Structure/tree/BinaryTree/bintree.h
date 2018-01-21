#ifndef _BIN_TREE_H_
#define _BIN_TREE_H_

typedef struct BinTreeNodeType {
  char data;

  struct BinTreeNodeType* pLeftChild;
  struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType {
  struct BinTreeNodeType* pRootNode;
} BinTree;

BinTree* createBinTree(BinTreeNode rootNode);
void deleteBinTree(BinTree* pBinTree);

BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void deleteBinTreeNode(BinTreeNode* pNode);

#endif