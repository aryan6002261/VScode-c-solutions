#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert a node at the beginning
void insertFirst(struct Node **headRef, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Insert a node at the end
void insertLast(struct Node **headRef, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node *last = *headRef;

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

// Insert a node at a given position
void insert(struct Node **headRef, int position, int newData) {

    // Insert at beginning
    if (position == 0) {
        insertFirst(headRef, newData);
        return;
    }

    struct Node *temp = *headRef;

    // Move to the node before the desired position
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Position is invalid
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = newData;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display the linked list
void display(struct Node *head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", head->data);
    display(head->next);
}

// Free allocated memory
void freeList(struct Node *head) {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;

    insertFirst(&head, 2);
    insertFirst(&head, 1);

    insertLast(&head, 3);
    insertLast(&head, 4);

    // Insert 8 at position 0
    insert(&head, 0, 8);

    display(head);

    freeList(head);

    return 0;
}