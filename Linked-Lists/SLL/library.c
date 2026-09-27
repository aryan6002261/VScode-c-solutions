#include<stdio.h>
#include<stdlib.h>

// DEFINING NODE
struct Node {
	int data;
	struct Node* next;
};


// CREATE A LINKED LIST
struct Node* createList(int n) {
	if (n==0) return NULL;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter the value of the node: ");
	scanf("%d", &(newNode->data));
	newNode->next = createList(n-1);
	return newNode;
}

// PRINT A LINKED LIST
void printList(struct Node* head) {
	if (head==NULL) {
		printf("Empty list\n");
		return;
	}
	struct Node* temp = head;
	while (temp!=NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

// INSERT A NODE AT FIRST POSITION
struct Node* insertFirst(struct Node* head, int val) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->next = head;
	return newNode;
}

// INSERT A NODE AT LAST POSITION
struct Node* insertLast(struct Node* head, int val) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->next = NULL;
	if (head==NULL) return newNode;
	struct Node* temp = head;
	while (temp->next!=NULL) temp = temp->next;
	temp->next = newNode;
	return head;
}

// INSERT A NODE AT ARBITRARY POSITION
struct Node* insertNode(struct Node* head, int val, int pos) {
	if (pos<1) return head;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	if (pos==1) {
		if (head==NULL) {
			newNode->next = NULL;
			return newNode;
		}
		newNode->next = head;
		head = newNode;
		return head;
	}
	struct Node* temp = head;
	for (int i=1; i<pos-1 && temp!=NULL; i++) temp = temp->next;
	if (temp==NULL) {
		free(newNode);
		return head;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	return head;
}


// DELETE THE FIRST NODE
struct Node* deleteFirst(struct Node* head) {
	if (head==NULL) return NULL;
	struct Node* del = head;
	head= head->next;
	free(del);
	return head;
}


// DELETE THE LAST NODE
struct Node* deleteLast(struct Node* head) {
	if (head==NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
	struct Node* temp = head;
	while (temp->next->next!=NULL) temp = temp->next;
	struct Node* del = temp->next;
	temp->next = NULL;
	free(del);
	return head;
}

// DELETE A NODE AT ARBITRARY POSITION
struct Node* deleteNode(struct Node* head, int pos) {
	if (pos<1) return head;
	if (head==NULL) return NULL;
	struct Node* temp = head;
	if (pos==1) {
		if (head->next==NULL) {
			free(head);
			return NULL;
		}
		head = temp->next;
		free(temp);
		return head;
	}
	for (int i=1; i<pos-1 && temp->next!=NULL; i++) temp=temp->next;
    if (temp->next == NULL) return head;
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    return head;
}

// REVERSE A LINKED LIST
struct Node* reverseList(struct Node* head) {
	struct Node* curr = head;
	struct Node* next = NULL;
	struct Node* prev = NULL;
	while(curr!=NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

// FIND A SPECIFIC NODE
int findNode(struct Node* head, int val) {
	struct Node* temp = head;
	int count = 0;
	while (temp!=NULL) {
		count++;
		if (temp->data==val) return count;
		temp = temp->next;
	}
	return -1;
}

// COUNT NUMBER OF NODES
int countNode(struct Node* head) {
	struct Node* temp = head;
	int count = 0;
	while (temp!=NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

// FIND NODE WITH MAXIMUM VALUE
int findMax(struct Node* head) {
	if (head==NULL) return -1;
	int max = head->data;
	struct Node* temp = head;
	while (temp!=NULL) {
		if (temp->data > max) max = temp->data;
		temp = temp->next;
	}
	return max;
}

// FIND NODE WITH MINIMUM VALUE
int findMin(struct Node* head) {
	if (head==NULL) return -1;
	int min = head->data;
	struct Node* temp = head;
	while (temp!=NULL) {
		if (temp->data < min) min = temp->data;
		temp = temp->next;
	}
	return min;
}

// FIND SUM OF ALL VALUES IN A LIST
int sumList(struct Node* head) {
    int sum = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

// FIND AVERAGE OF ALL VALUES IN A LIST
float avgList(struct Node* head) {
	if (head==NULL) return -1;
	return (float)sumList(head)/countNode(head);
}

// FIND THE MIDDLE NODE
struct Node* middleNode(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// GET A SPECIFIC NODE
struct Node* getNode(struct Node* head, int n) {
	if (head==NULL || n<1) return NULL;
	struct Node* temp = head;
	for (int i=1; i<n; i++) {
		if (temp==NULL) return NULL;
		temp = temp->next;
	}
	return temp;
}

// GET NODE AT A POSITION FROM END
struct Node* getFromLast(struct Node* head, int n) {
	return getNode(head, countNode(head)-n+1);
}

// SORT A LINKED LIST
void sortList(struct Node* head) {
    if (head == NULL) return;
    struct Node* i = head;
    while (i != NULL) {
        struct Node* j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

// CONCATENATE TWO LINKED LISTS
struct Node* concatenateList(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    struct Node* temp = head1;
    while (temp->next != NULL) temp = temp->next;
    temp->next = head2;
    return head1;
}

// COPY A LIST TO ANOTHER
struct Node* copyList(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* newHead = NULL;
    struct Node* tail = NULL;
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = temp->data;
        newNode->next = NULL;
        if (newHead == NULL) {
            newHead = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        temp = temp->next;
    }
    return newHead;
}

// CHECK WHETHER A LIST IS A PALINDROME
int isPalindrome(struct Node* head) {
    if (head==NULL || head->next==NULL) return 1;
    for (int i=1; i<=countNode(head)/2; i++) {
    	if ((getNode(head,i)->data) != (getFromLast(head,i)->data)) return 0;
	}
	return 1;
}

// FREE THE LINKED LIST
void freeList(struct Node* head) {
	while (head!=NULL) {
		struct Node* temp = head;
		head = head->next;
		free(temp);
	}
}

int main() {
    struct Node* head = NULL;
    struct Node* head2 = NULL;
    struct Node* result = NULL;

    int choice;
    int n, val, pos;
    int resultInt;
    float resultFloat;

    while (1) {

        printf("\n========== LINKED LIST MENU ==========\n");
        printf("1.  Create a linked list\n");
        printf("2.  Print a linked list\n");
        printf("3.  Insert node at first position\n");
        printf("4.  Insert node at last position\n");
        printf("5.  Insert node at arbitrary position\n");
        printf("6.  Delete first node\n");
        printf("7.  Delete last node\n");
        printf("8.  Delete node at arbitrary position\n");
        printf("9.  Reverse linked list\n");
        printf("10. Find a specific node\n");
        printf("11. Count number of nodes\n");
        printf("12. Find maximum value\n");
        printf("13. Find minimum value\n");
        printf("14. Find sum of all values\n");
        printf("15. Find average of all values\n");
        printf("16. Find middle node\n");
        printf("17. Get node at a position\n");
        printf("18. Get node from end\n");
        printf("19. Sort linked list\n");
        printf("20. Concatenate two linked lists\n");
        printf("21. Copy linked list\n");
        printf("22. Check palindrome\n");
        printf("23. Free linked list\n");
        printf("24. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                freeList(head);
                head = createList(n);

                printf("List created successfully.\n");
                break;


            case 2:
                printList(head);
                break;


            case 3:
                printf("Enter value: ");
                scanf("%d", &val);

                head = insertFirst(head, val);

                printf("Node inserted.\n");
                break;


            case 4:
                printf("Enter value: ");
                scanf("%d", &val);

                head = insertLast(head, val);

                printf("Node inserted.\n");
                break;


            case 5:
                printf("Enter value: ");
                scanf("%d", &val);

                printf("Enter position: ");
                scanf("%d", &pos);

                head = insertNode(head, val, pos);

                printf("Operation completed.\n");
                break;


            case 6:
                head = deleteFirst(head);

                printf("First node deleted.\n");
                break;


            case 7:
                head = deleteLast(head);

                printf("Last node deleted.\n");
                break;


            case 8:
                printf("Enter position: ");
                scanf("%d", &pos);

                head = deleteNode(head, pos);

                printf("Operation completed.\n");
                break;


            case 9:
                head = reverseList(head);

                printf("List reversed.\n");
                break;


            case 10:
                printf("Enter value to find: ");
                scanf("%d", &val);

                resultInt = findNode(head, val);

                if (resultInt == -1)
                    printf("Node not found.\n");
                else
                    printf("Node found at position %d.\n", resultInt);

                break;


            case 11:
                resultInt = countNode(head);

                printf("Number of nodes: %d\n", resultInt);
                break;


            case 12:
                resultInt = findMax(head);

                if (head == NULL)
                    printf("List is empty.\n");
                else
                    printf("Maximum value: %d\n", resultInt);

                break;


            case 13:
                resultInt = findMin(head);

                if (head == NULL)
                    printf("List is empty.\n");
                else
                    printf("Minimum value: %d\n", resultInt);

                break;


            case 14:
                resultInt = sumList(head);

                printf("Sum: %d\n", resultInt);
                break;


            case 15:
                resultFloat = avgList(head);

                if (head == NULL)
                    printf("List is empty.\n");
                else
                    printf("Average: %.2f\n", resultFloat);

                break;


            case 16:
                result = middleNode(head);

                if (result == NULL)
                    printf("List is empty.\n");
                else
                    printf("Middle node: %d\n", result->data);

                break;


            case 17:
                printf("Enter position: ");
                scanf("%d", &n);

                result = getNode(head, n);

                if (result == NULL)
                    printf("Invalid position.\n");
                else
                    printf("Node at position %d: %d\n",
                           n, result->data);

                break;


            case 18:
                printf("Enter position from end: ");
                scanf("%d", &n);

                result = getFromLast(head, n);

                if (result == NULL)
                    printf("Invalid position.\n");
                else
                    printf("Node %d from end: %d\n",
                           n, result->data);

                break;


            case 19:
                sortList(head);

                printf("List sorted.\n");
                break;


            case 20:
                printf("Create second list first.\n");
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                head2 = createList(n);

                head = concatenateList(head, head2);

                head2 = NULL;

                printf("Lists concatenated.\n");
                break;


            case 21:
                result = copyList(head);

                if (result == NULL)
                    printf("List is empty.\n");
                else {
                    printf("Copied list: ");
                    printList(result);
                    freeList(result);
                }

                break;


            case 22:
                if (isPalindrome(head))
                    printf("The list is a palindrome.\n");
                else
                    printf("The list is not a palindrome.\n");

                break;


            case 23:
                freeList(head);
                head = NULL;

                printf("List freed.\n");
                break;


            case 24:
                freeList(head);
                printf("Exiting...\n");
                return 0;


            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
