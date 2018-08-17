//for unit test for binary search tree

typedef struct treeNode
{
  int data;
  struct treeNode *left;
  struct treeNode *right;
}treeNode;

//BST operations

treeNode* FindMin(treeNode *node);
treeNode* FindMax(treeNode *node);
treeNode * Insert(treeNode *node,int data);
treeNode * Find(treeNode *node, int data);
treeNode * Delete(treeNode *node, int data);
