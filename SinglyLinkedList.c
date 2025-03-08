#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}LNode,*List;

LNode L;

List InitList(List PtrL) {// Initialization list
	PtrL = (List) malloc(sizeof(L));
	PtrL->next = NULL;
	return PtrL;
}

List CreateFromHead(List PtrL, int x) { 
	List s;
	s = (List) malloc (sizeof(L));
	s->data = x;
	s->next = PtrL->next;
	PtrL->next = s;
	return PtrL;
}

int Length(List PtrL) {
    int counter = 0;
    List current = PtrL->next;

    while (current != NULL)
    {
        counter++;
        current = current->next;
    }
	return 0;
}

List FindKth(List PtrL, int k) {
    List current = PtrL;

    for (int i = 0; i < k && PtrL != NULL; i++)
    {
        current = current->next;
    }

return PtrL;
}

List Insert(List PtrL, int i, int x) { 
    List current = PtrL;

    for (int j = 0; j < i - 1 && current != NULL; j++)
    {
        current = current->next;
    }
        if (current != NULL)
        {
            List newNode =(List)malloc(sizeof(L));
            newNode->data = x;
            newNode->next = current->next;
            current->next = newNode;
        }

	return PtrL;
}

List Delete(List PtrL, int i) {
    List current = PtrL;

    for (int j = 0; j < i-1; j++)
    {
        current = current->next;
    }
    if (current != NULL && current->next != NULL)
    {
        current->next = current->next->next;
    }

return PtrL;
}

void print(List PtrL) { // print the list
	List start;
	for(start = PtrL->next; start != NULL; start=start->next)
	printf("%d ",start->data);
}


int main() {
	List list, s;
	int m;
	list = InitList(list);
	for(int i=1;i<5;i++){
		list = CreateFromHead(list,i);
	} 
	printf("List Data ：");
	print(list);
	printf("\n");
	list = Insert(list,3,9);
	printf("insert 9 before the third node：");
	print(list);
	printf("\n");
	m = Length(list);
	printf("length of the list ：%d", m);
	printf("\n");
	Delete(list,2);
	printf("Delete the second node ：");
	print(list);
	printf("\n");
	m = Length(list);
	printf("length of the list：%d", m);
	printf("\n");
	s = FindKth(list,3);
	printf("the third node is %d", s->data);
	return 0;
}
