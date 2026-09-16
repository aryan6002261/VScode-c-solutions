#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList(int n) {
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;

    for (int i = 0; i < n; i++) {
        newNode = malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
            newNode->next = head;
        } else {
            temp->next = newNode;
            newNode->next = head;
            temp = newNode;
        }
    }

    return head;
}

int main() {
    struct Node *head;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Circular linked list created successfully.\n");

    return 0;
}