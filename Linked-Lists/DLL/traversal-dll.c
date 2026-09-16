#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

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

    printf("DLL: ");
    traverse(head);

    return 0;
}