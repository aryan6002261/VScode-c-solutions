#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Creates a linked list recursively
struct Node* createList(int n) {
    if (n <= 0) return NULL; // Fix: Handle negative inputs safely
    
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

// Reverses the linked list iteratively
struct Node* reverseList(struct Node* head) {
    struct Node* curr = head;
    struct Node* nextNode = NULL;
    struct Node* prev = NULL;
    
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Counts the number of nodes
int countList(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Searches for a key
int searchKey(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1; // Key not found
}

// Helper function to free memory before exiting
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, key;
    printf("Enter the number of nodes = ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input.\n");
        return 1;
    }
    
    printf("Enter the node values:\n");
    struct Node* head = createList(n);
    
    printf("\nOriginal list:\n");
    printList(head);
    
    struct Node* newHead = reverseList(head);
    
    printf("\nReversed list:\n");
    printList(newHead);
    
    printf("\nNumber of nodes = %d\n", countList(newHead));
    
    printf("\nEnter the key to search = ");
    scanf("%d", &key);
    
    int pos = searchKey(newHead, key);
    if (pos != -1) {
        printf("Position of %d = %d\n", key, pos);
    } else {
        printf("Key %d not found in the list.\n", key);
    }
    
    // Always free allocated memory
    freeList(newHead); 
    return 0;
}
