#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Creating the linked list
struct Node* createList(int n) {
    if (n <= 0) return NULL;
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    scanf("%d", &(newNode->data));
    newNode->next = createList(n - 1);
    return newNode;
}

// Prints the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Inserts a node at any 1-indexed position
struct Node* insertList(struct Node* head, int num, int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return head;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = num;
    newNode->next = NULL;

    // Insert at the head
    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    // Traverse to the node right before the target position
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If temp is NULL, the position is out of bounds
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return head;
    }

    // Insert into position (handles middle and end safely)
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Deletes a node at any 1-indexed position
struct Node* deleteList(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (pos <= 0) {
        printf("Invalid position\n");
        return head;
    }

    struct Node* temp = head;

    // Case 1: Delete the head node
    if (pos == 1) {
        head = head->next;
        free(temp);
        return head;
    }

    // Traverse to the node right before the one to be deleted
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Check if target position or the node to delete doesn't exist
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return head;
    }

    // Case 2: Node found, clear it safely from memory
    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);

    return head;
}

int main() {
    int n, choice, num, pos;
    printf("Enter the number of nodes = ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input.\n");
        return 1;
    }
    
    printf("Enter the values for your %d nodes:\n", n);
    struct Node* head = createList(n);

    while (true) {
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            printf("Enter the number to insert = ");
            scanf("%d", &num);
            printf("Enter the position = ");
            scanf("%d", &pos);
            head = insertList(head, num, pos);
        } else if (choice == 2) {
            printf("Enter the position to delete = ");
            scanf("%d", &pos);
            head = deleteList(head, pos);
        } else if (choice == 3) {
            printList(head);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    // Free remaining list memory before exiting program
    while (head != NULL) {
        struct Node* next = head->next;
        free(head);
        head = next;
    }

    return 0;
}
