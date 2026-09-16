#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* deleteAtPosition(struct Node *head, int pos) {
    struct Node *temp;
    struct Node *last;

    if (head == NULL)
        return NULL;

    // Delete first node
    if (pos == 1) {

        // Only one node
        if (head->next == head) {
            free(head);
            return NULL;
        }

        // Find last node
        last = head;

        while (last->next != head) {
            last = last->next;
        }

        temp = head;
        head = head->next;

        last->next = head;

        free(temp);

        return head;
    }

    temp = head;

    // Reach position pos - 1
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;

        if (temp == head) {
            printf("Invalid position\n");
            return head;
        }
    }

    // Check if position exists
    if (temp->next == head) {
        printf("Invalid position\n");
        return head;
    }

    struct Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    free(deleteNode);

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
    struct Node *first, *second, *third, *fourth;
    int pos;

    first = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));
    fourth = malloc(sizeof(struct Node));

    first->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = first;

    head = first;

    printf("Before deletion: ");
    traverse(head);

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    head = deleteAtPosition(head, pos);

    printf("After deletion: ");
    traverse(head);

    return 0;
}