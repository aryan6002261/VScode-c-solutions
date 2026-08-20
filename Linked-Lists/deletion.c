#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a linked list with n nodes
struct Node *create(int n) {
    if (n == 0)
        return NULL;

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    scanf("%d", &head->data);

    head->next = create(n - 1);

    return head;
}

// Delete the first node
void deleteFirst(struct Node **headRef) {
    if (*headRef == NULL)
        return;

    struct Node *temp = *headRef;

    *headRef = (*headRef)->next;

    free(temp);
}

// Delete the last node
void deleteLast(struct Node **headRef) {
    if (*headRef == NULL)
        return;

    // Only one node
    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        return;
    }

    struct Node *temp = *headRef;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Delete node at a given position
void deletePos(struct Node **headRef, int pos) {
    if (*headRef == NULL)
        return;

    // Delete first node
    if (pos == 0) {
        deleteFirst(headRef);
        return;
    }

    struct Node *temp = *headRef;

    // Move to the node before the target
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    struct Node *toDelete = temp->next;

    temp->next = toDelete->next;

    free(toDelete);
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

// Free the entire linked list
void freeList(struct Node *head) {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;

    printf("How many nodes do you want? ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    struct Node *head = create(n);

    // Delete first and last nodes
    deleteFirst(&head);
    deleteLast(&head);

    // Example: delete node at position 1
    deletePos(&head, 3);
    
    printf("\nAfter deleting first and last elements:\n");
    display(head);

    freeList(head);

    return 0;
}