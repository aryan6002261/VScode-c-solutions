#include<stdio.h>
#define MAX 100

void read(int nums[MAX], int n) {
	for (int i=0; i<n; i++) {
		scanf("%d", &nums[i]);
	}
}

void display(int nums[MAX], int n) {
	for (int i=0; i<n; i++) {
		printf("%d ", nums[i]);
	}
}

// INSERTION
void insert(int nums[], int *n, int pos, int ele) {
	if (pos<0 || pos>*n || *n>=MAX) return;

	for (int *ptr = nums+*n-1; ptr>=nums+pos; ptr--) {
		*(ptr+1) = *ptr;
	}

	nums[pos] = ele;
	(*n)++;
}

// DELETION
void delete(int nums[], int *n, int pos) {
	if (pos<0 || pos>=*n) return;

	for (int *ptr = nums+pos; ptr<nums+*n-1; ptr++) {
		*ptr = *(ptr+1);
	}

	(*n)--;
}

int main() {
	int nums[MAX], pos, ele, n;

	printf("How many elements do you want in the array?\n");
	scanf("%d", &n);

	printf("\nEnter %d elements:\n", n);
	read(nums, n);

	// TRAVERSAL
	printf("\nOriginal array:\n");
	display(nums, n);

	// INSERTION
	printf("\n\nWhich element do you want to insert?\n");
	scanf("%d", &ele);

	printf("\nOn what position do you want to insert it?\n");
	scanf("%d", &pos);

	insert(nums, &n, pos, ele);

	printf("\nArray after insertion:\n");
	display(nums, n);

	// DELETION
	printf("\n\nFrom what position do you want to delete?\n");
	scanf("%d", &pos);

	delete(nums, &n, pos);

	printf("\nArray after deletion:\n");
	display(nums, n);

	return 0;
}