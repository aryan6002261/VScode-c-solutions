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

void search(int nums[], int n, int ele) {
	for (int i=0; i<n; i++) {
		if (nums[i] == ele) {
			printf("\nElement found at position %d", i);
			return;
		}
	}

	printf("\nElement not found");
}

int main() {
	int nums[MAX], ele, n;

	printf("How many elements do you want in the array?\n");
	scanf("%d", &n);

	printf("\nEnter %d elements:\n", n);
	read(nums, n);

	printf("\nOriginal array:\n");
	display(nums, n);

	printf("\n\nWhich element do you want to search?\n");
	scanf("%d", &ele);

	search(nums, n, ele);

	return 0;
}