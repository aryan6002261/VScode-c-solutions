#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* create(int n) {
	struct Node* head = NULL;
	struct Node* last = NULL;
	struct Node* newNode = NULL;
	for (int i=1; i<=n; i++) {
		newNode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter the value for node-%d\n", i);
		scanf("%d", &newNode->data);
		newNode->next = NULL;
		
		if (head==NULL) head = newNode;
		else last->next = newNode;
			
		last = newNode;
	}
	return head;
}

void display(struct Node* head) {
	struct Node* temp = head;
	while (temp!=NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main() {
	struct Node *node1;
	
	int n;
	printf("How many nodes do you want?\n");
	scanf("%d", &n);
	
	node1 = create(n);
	display(node1);
	
	return 0;
}