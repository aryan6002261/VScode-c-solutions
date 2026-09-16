#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* deleteAtPosition(struct Node *head, int pos) {
    struct Node *temp;

    if (head == NULL)
        return NULL;

    temp = head;

    // Delete first node
    if (pos == 1) {
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        free(temp);

        return head;
    }

    // Reach position pos
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

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
    struct Node *first, *second, *third, *fourth;
    int pos;

    first = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));
    fourth = malloc(sizeof(struct Node));

    first->data = 10;
    first->prev = NULL;
    first->next = second;

    second->data = 20;
    second->prev = first;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = fourth;

    fourth->data = 40;
    fourth->prev = third;
    fourth->next = NULL;

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