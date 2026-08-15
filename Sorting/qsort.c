#include<stdio.h>
#include<stdlib.h>
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

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int nums[MAX], n;
	
	printf("How many elements do you want?\n");
	scanf("%d", &n);
	
	printf("\nEnter %d elements:\n", n);
	read(nums, n);
	
	printf("\nOriginal Array:\n");
	display(nums, n);
	
	qsort(nums, n, sizeof(int), compare);
	printf("\n\nSorted Array:\n");
	display(nums, n);
	
	return 0;
}