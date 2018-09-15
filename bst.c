#include <stdio.h>
#include <stdlib.h>
#include "assignment3.h"

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
