#include <stdio.h>
#include <stdlib.h>
#include "assignment3.h"


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
