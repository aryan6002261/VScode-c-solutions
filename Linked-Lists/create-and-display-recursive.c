#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* create(int n) {
	struct Node* head;
	
	if (n==0) return NULL;
	
	head = (struct Node*)malloc(sizeof(struct Node));
	scanf("%d", &head->data);
	
	head->next = create(n-1);
	
	return head;
}

void display(struct Node* head) {
	struct Node* temp = head;
	
	if (temp==NULL) {
		printf("NULL\n");
		return;
	}
	printf("%d -> ", temp->data);
	display(temp->next);
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