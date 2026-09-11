#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    if (n==0) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL; 
    }
    scanf("%d", &(newNode->data));
    newNode->next = createList(n-1);
    return newNode;
}

void printList(struct Node* head) {
    if (head==NULL) return;
    struct Node* temp = head;
    while (temp!=NULL) {
        printf("%d -> ", (temp->data));
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

struct Node* insertList(struct Node* head, int num, int pos) {
    if (pos<=0) {
        printf("Invalid position\n");
        return NULL;
    }
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;
    if (pos == 1 || head == NULL) {
        newNode->next = head;
        return newNode;
    }
    struct Node* temp = head;
    for (int i=1; i<pos-1 && temp!=NULL; i++) {
        temp = temp->next;
    }
    if (temp==NULL || temp->next==NULL) {
        printf("Invalid position\n");
        free(newNode);
        newNode = NULL;
        return head;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

struct Node* deleteList(struct Node* head, int pos) {
    if (head==NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* temp = head;
    for (int i=1; i<pos-1 && temp!=NULL; i++) {
        temp = temp->next;
    }
    if (temp==NULL || temp->next==NULL) {
        printf("Invalid position\n");
        return head;
    } else {
        temp->next = temp->next->next;
    }
    return head;
}

int main() {
    int n, choice, num, pos;
    printf("Enter the number of nodes = ");
    scanf("%d", &n);
    struct Node* head = createList(n);
    while (true) {
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        if (choice==1) {
            printf("Enter the number to insert = ");
            scanf("%d", &num);
            printf("Enter the position = ");
            scanf("%d", &pos);
            head = insertList(head, num, pos);
        } else if (choice==2) {
            printf("Enter the position to delete = ");
            scanf("%d", &pos);
            head = deleteList(head, pos);
        } else if (choice==3) {
            printList(head);
        } else if (choice==4) break;
        else printf("Invalid choice\n");
    }
    return 0;
}
