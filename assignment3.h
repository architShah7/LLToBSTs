/* File assignment3.h */

#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

/* Node in a BST */
struct TreeNode {
  int key;
  struct TreeNode *left;  /* pointer to left child */
  struct TreeNode *right; /* pointer to right child */
};

/* Node in a linked list */
struct ListNode {
  int key;
  struct ListNode *next; /* pointer to the next item in a list */
};

typedef struct TreeNode *TreeNodePtr;
typedef struct ListNode *ListNodePtr;

/* STORE THE BODIES OF THE NEXT FUNCTIONS IN FILE bst.c */

/* createBSTnode allocates a node of type TreeNode and initializes it
   with key and left=right=NULL. createBSTnode returns a pointer to
   this node.  If memory cannot be allocated, NULL is returned. */
TreeNodePtr createBSTnode(int key);

/* insertNodeIntoBST inserts a node into a BST. root points to the
   root of the tree and z points to a node to be
   inserted. insertNodeIntoBST returns a pointer to the root of the
   tree (with z inserted). */
TreeNodePtr insertNodeIntoBST(TreeNodePtr root, const TreeNodePtr z);

/* insertArrayIntoBST inserts n elements of array A into a BST and
   returns the pointer to the root of the BST. */
TreeNodePtr insertArrayIntoBST(int n, int *A);

/* deallocateBST frees all the nodes of a BST. root points to the root
   of the BST. */
void deallocateBST(TreeNodePtr root);

/* convertBSTtoLinkedList inserts the nodes of a BST into a linked
   list. The BST is processed in in-order. The keys are inserted such
   that the list is sorted in non-decreading order.  A pointer to the
   linked list is returned.
*/
ListNodePtr convertBSTtoLinkedList(TreeNodePtr root);

/* STORE THE BODIES OF THE NEXT FUNCTIONS IN FILE list.c. */

/* reverseList reverses a linked list and returns a pointer to the
   reversed list. head points to the beginning of the list. */
ListNodePtr reverseList(ListNodePtr head);

/* deallocateList fees all the nodes of a linked list. head is a
   pointer to the beginning of the list. */
void deallocateList(ListNodePtr head);

/* STORE THE BODIES OF THE NEXT FUNCTIONS IN FILE aux.c. */

/* generatRandomIntArray fills an array of size N with random integers
   between 0 and NMAX-1.
*/
void generateRandomIntArray(int N, int *A, int NMAX);

/* Outputs the array A */
void printArray(int n, int *A);

/* Outputs the keys in a BST in in-order. root points to the root of
   the BST. */
void printBSTinorder(TreeNodePtr root);

/* Outputs the keys in a linked list. head points to the beginning of
   the list. */
void printList(ListNodePtr head);

#endif /* ASSIGNMENT3_H */
