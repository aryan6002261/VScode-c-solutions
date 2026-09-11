#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    if (n==0) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL; 
    }
    scanf("%d", &(newNode->data));
    newNode->next = createList(n-1);
    return newNode;
}

void printList(struct Node* head) {
    if (head==NULL) return;
    struct Node* temp = head;
    while (temp!=NULL) {
        printf("%d -> ", (temp->data));
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

struct Node* reverseList(struct Node* head) {
    struct Node* curr = head;
    struct Node* nextNode = NULL;
    struct Node* prev = NULL;
    while (curr!=NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int countList(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    while(temp!=NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int searchKey(struct Node* head, int key) {
    struct Node* temp = head;
    int n = countList(head);
    for (int i=1; i<=n; i++) {
        if ((temp->data)==key) return i;
        temp = temp->next;
    }
    return -1;
}

int main() {
    int n, key;
    printf("Enter the number of nodes = ");
    scanf("%d", &n);
    struct Node* head = createList(n);
    printf("\nOriginal list:\n");
    printList(head);
    struct Node* newHead = reverseList(head);
    printf("\nReversed list:\n");
    printList(newHead);
    printf("\nNumber of nodes = %d\n", countList(newHead));
    printf("\nEnter the key to search = ");
    scanf("%d", &key);
    printf("Position of %d = %d\n", key, searchKey(newHead, key));
    return 0;
}
