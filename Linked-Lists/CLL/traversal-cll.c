#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

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

    printf("CLL: ");
    traverse(head);

    return 0;
}