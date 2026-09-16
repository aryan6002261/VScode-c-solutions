#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* insertAtPosition(struct Node *head, int data, int pos) {
    struct Node *newNode;
    struct Node *temp;

    newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Insert at beginning
    if (pos == 1) {
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        return newNode;
    }

    temp = head;

    // Reach position pos - 1
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

void traverse(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct Node *head;
    struct Node *first, *second, *third;
    int data, pos;

    first = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));

    first->data = 10;
    first->prev = NULL;
    first->next = second;

    second->data = 20;
    second->prev = first;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = NULL;

    head = first;

    printf("Before insertion: ");
    traverse(head);

    printf("Enter data: ");
    scanf("%d", &data);

    printf("Enter position: ");
    scanf("%d", &pos);

    head = insertAtPosition(head, data, pos);

    printf("After insertion: ");
    traverse(head);

    return 0;
}