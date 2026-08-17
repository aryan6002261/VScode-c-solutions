#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void insertFirst(struct Node** headRef, int newData) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->next = *headRef;
	*headRef = newNode;
}

void printList(struct Node* n) {
	while (n!=NULL) {
		printf("%d -> ", n->data);
		n = n->next;
	}
	printf("NULL");
}

int main() {
	struct Node* head = NULL;
	
	insertFirst(&head, 30);
    insertFirst(&head, 20);
    insertFirst(&head, 10);
    printList(head);
    
    return 0;
}