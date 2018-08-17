//unit tests for binary search tree

#include "prog.h"

/* utility function */
treeNode * Create(int data) {
  treeNode *node = malloc(sizeof(treeNode));
  node->data = 0;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int Size(treeNode *);


/*
 * recursion on left where deleted node has no sub-content
 */
void test1() {
  treeNode *parent = Create(1);
  treeNode *child = Insert(parent, 0);

  Delete(parent, 0);

  assert(Find(parent, 1) != NULL);
  assert(Find(parent, 0) == NULL);
  assert(Size(parent) == 1);
}

/*
 * recursion on right where deleted node has children on both left and right
 */
void test2() {
  treeNode *parent = Create(0);
  treeNode *child = Insert(parent, 2);
  Insert(child, 1);
  Insert(child, 3);

  Delete(parent, 2);

  assert(Find(parent, 0) != NULL);
  assert(Find(parent, 1) != NULL);
  assert(Find(parent, 2) == NULL);
  assert(Find(parent, 3) != NULL);
  assert(Size(parent) == 3);
}

/*
 * no recursion, deleted node has only a left child, right is NULL
 */
void test3() {
  treeNode *parent = Create(1);
  treeNode *child = Insert(parent, 0);
  /*
   * Based on the code as written, this assert WILL fail, but the code is wrong,
   * as when the parent is deleted, only the child is left, so it must be the new parent...
   */
  treeNode *newTree = Delete(parent, 1);
  assert(newTree == child);
  assert(Size(newTree) == 1);
}

/*
 * untested:
 * 1. deleted node has only a right child, left is NULL
 * 2. data value to be deleted does not exist in tree
 * 3. tree is empty (redundant to what I already have for coverage but good to check nonetheless)
 */
