#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
	int roll;
	char name[50];
	float marks;
	struct Node* next;
};

int hash(int key) {
	return key%10;
}

void insert(struct Node** table, int roll, char name[50], float marks) {
	int key = hash(roll);
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->roll = roll;
	strcpy(newNode->name, name);
	newNode->marks = marks;
	newNode->next = table[key];
	table[key] = newNode;
}

void remove(struct Node** table, int roll) {
    int key = hash(roll);
    struct Node* temp = table[key];
    struct Node* prev = NULL;
    while (temp != NULL) {
        if (temp->roll == roll) {
            if (prev == NULL)
                table[key] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

char* search(struct Node** table, int roll) {
	int key = hash(roll);
	struct Node* temp = table[key];
	while (temp!=NULL) {
		if (temp->roll==roll) return temp->name;
		temp = temp->next;
	}
	return NULL;
}

int main() {
    struct Node* table[10] = {NULL};

    int choice, roll;
    char name[50];
    float marks;
    char* result;

    while (1) {
        printf("\n===== STUDENT HASH TABLE =====\n");
        printf("1. Insert Student\n");
        printf("2. Search Student\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nEnter roll number: ");
                scanf("%d", &roll);

                printf("Enter name: ");
                scanf(" %[^\n]", name);

                printf("Enter marks: ");
                scanf("%f", &marks);

                insert(table, roll, name, marks);

                printf("Student inserted successfully!\n");
                break;

            case 2:
                printf("\nEnter roll number to search: ");
                scanf("%d", &roll);

                result = search(table, roll);

                if (result != NULL)
                    printf("Student found: %s\n", result);
                else
                    printf("Student not found!\n");

                break;

            case 3:
                printf("\nEnter roll number to delete: ");
                scanf("%d", &roll);

                remove(table, roll);

                printf("Delete operation completed.\n");
                break;

            case 4:
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
