#include <stdio.h>
#include <stdlib.h>
#include "assignment3.h"

/*FILE aux.c*/

void generateRandomIntArray(int N, int *A, int NMAX){
    int i;
    for (i=0; i<N; i++){
        A[i] = rand()%NMAX;
    }
}

void printArray(int n, int *A){
    int i;
    for (i=0; i<n; i++){
        printf("%d  ", A[i]);
    }

}

void printBSTinorder(TreeNodePtr root){
    if(root == NULL){
      return;
    }
    printBSTinorder(root->left);

    printf("%d  ", root->key);

    printBSTinorder(root->right);


}

void printList(ListNodePtr head){

    if(head == NULL){
      return;
    }

    printf("%d  ", head->key);
    printList(head->next);

}


/*FILE bst.c */

TreeNodePtr createBSTnode(int key){
    TreeNodePtr newNode = (TreeNodePtr)malloc(sizeof(struct TreeNode));

    if(newNode == NULL){
        return NULL;
    }

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


TreeNodePtr insertNodeIntoBST(TreeNodePtr root, const TreeNodePtr z){
    if(root == NULL){
        root = z;
        return root;
    }
    else if(z->key <= root->key){
        root->left = insertNodeIntoBST(root->left, z);
    }
    else if(z->key > root->key){
        root->right = insertNodeIntoBST(root->right, z);
    }

    return root;
}



TreeNodePtr insertArrayIntoBST(int n, int *A){
    TreeNodePtr root = NULL;
    TreeNodePtr z;
    int i;
    for(i = 0; i < n; i++){
        z = createBSTnode(A[i]);
    	root = insertNodeIntoBST(root,z);


    }

    return root;
}


void deallocateBST(TreeNodePtr root){
    if(root == NULL){
        return;
    }
    deallocateBST(root->left);
    deallocateBST(root->right);
    free(root);

}


ListNodePtr convertBSTtoLinkedList(TreeNodePtr root){

	ListNodePtr left, right, merger;
	ListNodePtr middle=(ListNodePtr)malloc(sizeof(struct ListNode));

	if(root->right != NULL){
		right = convertBSTtoLinkedList(root->right);
	}else{
		right = NULL;
	}

	middle->key = root->key;
	middle->next = right;

	if(root->left != NULL){
		left = convertBSTtoLinkedList(root->left);
	}else{
		left = NULL;
	}


	if(left != NULL){
        merger = left;
        while (merger->next){
            merger=merger->next;
        }

        merger->next = middle;
        return left;
	}else{
		return middle;
	}


 }


 /*FILE list.c */

 ListNodePtr reverseList(ListNodePtr head){
	ListNodePtr nodeBefore = NULL;
    ListNodePtr nodeAfter;

    while(head)
    {
        nodeAfter = head->next;
        head->next = nodeBefore;
        nodeBefore = head;
        head = nodeAfter;
    }

    head = nodeBefore;

    return head;
}


void deallocateList(ListNodePtr head){
    if(head == NULL){
        return;
    }
    deallocateList(head->next);
    free(head);

}

/* FILE primegap.c*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

unsigned long primeGap(const mpz_t a, const mpz_t b){

	mpz_t first, last, primeNow, primeBefore, primegap, largestgap;


	mpz_init(first);
	mpz_init(last);
	mpz_init(primeNow);
	mpz_init(primeBefore);
	mpz_init(primegap);
	mpz_init(largestgap);

	mpz_set(first,a);
	mpz_set(last,b);

	unsigned long gap;
	int reps = 40; /*good between 15 and 50*/


	if(mpz_probab_prime_p(first,reps) == 2 || mpz_probab_prime_p(first,reps) == 1){
		mpz_set(primeNow, first);

	}else{
		mpz_nextprime(primeNow,first);
	}

	while(mpz_cmp(last, primeNow) > 0){ /*While current prime is less than the final value*/

		mpz_set(primeBefore, primeNow);
    	mpz_nextprime(primeNow, primeBefore);
		mpz_sub(primegap, primeNow, primeBefore);

		if (mpz_cmp(primegap,largestgap) > 0){
			mpz_set(largestgap, primegap);
		}


	}


	gap = mpz_get_ui(largestgap);

	return gap;

}



/* FILE main_bst.c */
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

/*FILE main_primegap.c*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>


/* primeGap takes to integers, a and b of time mpz_t and returns the
   largest prime gap in the interval [a,b]. If no such a gap, primeGap
   returns 0. */
extern unsigned long primeGap(const mpz_t a, const mpz_t b);
extern double getTime();

int main(int argc, char* argv[])
{
  if (argc < 3)
    {
      printf("Usage: ./primesgap a b\n");
      return 0;
    }

  /* start timing */
  double time = getTime();

  mpz_t a, b;

  /* obtain the input bounds as long inttegers */
  unsigned long int la, lb;
  sscanf(argv[1],"%lu",&la);
  sscanf(argv[2],"%lu",&lb);

  /* convert the arguments to gmp integers */
  mpz_init_set_str (a, argv[1], 10);
  mpz_init_set_str (b, argv[2], 10);

  unsigned long max_gap = primeGap(a,b);
  printf("\nLargest prime gap in [%ld, %ld] is %ld\n", la, lb, max_gap);
  time = getTime()-time;
  printf("computed in %.1e seconds\n\n", time);

  return 0;
}







