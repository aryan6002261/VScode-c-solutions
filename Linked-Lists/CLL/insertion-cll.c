#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insertAtPosition(struct Node *head, int data, int pos) {
    struct Node *newNode;
    struct Node *temp;

    newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    // Empty list
    if (head == NULL) {
        if (pos != 1) {
            free(newNode);
            return NULL;
        }

        newNode->next = newNode;
        return newNode;
    }

    // Insert at beginning
    if (pos == 1) {
        temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;

        return newNode;
    }

    temp = head;

    // Reach position pos - 1
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;

        if (temp == head) {
            printf("Invalid position\n");
            free(newNode);
            return head;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void traverse(struct Node *head) {
    struct Node *temp;

    if (head == NULL)
        return;

    temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

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
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = first;

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