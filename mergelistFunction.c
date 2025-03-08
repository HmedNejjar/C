#include <stdio.h>

typedef struct ListNode
{
    int val;
    struct ListNode* next;

}LNode;

LNode* mergeTwoList(LNode* list1, LNode* list2)
{   
    LNode* merged = (LNode*) malloc(sizeof(LNode));   //make new list to merge list1 and list2
    LNode* current = merged;   //make pointer to list to traverse it
    merged->next = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)  
        {
            current->next = list1;    //pointer points at list1 element since it is smaller
            list1 = list1->next;    //move to next list1 element
        }
        else
        {
            current->next = list2;  //same thing for list2 if it is <=
            list2 = list2->next;
        }

        current = current->next;    
    }

    if (list1 != NULL)
    {
        current->next = list1;
    }
    else
    {
        current->next = list2;
    }

    return merged->next;

}
