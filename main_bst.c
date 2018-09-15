/* file main_bst.c */
#include <stdio.h>
#include <stdlib.h>

#include "assignment3.h"

int main(int argc, char *argv[]) {

  if (argc < 3 )
    {
      printf("\n Usage: ./bst n  nmax\n n is the number of integers between 0 and nmax-1\n");
      return 1;
    }
  int N = atoi(argv[1]), NMAX = atoi(argv[2]);

  int *A = malloc(N * sizeof(int));

  generateRandomIntArray(N, A, NMAX);
  printf("Array\n");
  printArray(N, A);
  printf("\n");

  TreeNodePtr bst_root = insertArrayIntoBST(N, A);
  printf("BST\n");
  printBSTinorder(bst_root);
  printf("\n");


  ListNodePtr list_head = convertBSTtoLinkedList(bst_root);
  printf("Linked list\n");
  printList(list_head);
  printf("\n");

  list_head = reverseList(list_head);
  printf("Reversed linked list\n");
  printList(list_head);
  printf("\n");

  deallocateBST(bst_root);
  deallocateList(list_head);
  free(A);
  return 0;
}
