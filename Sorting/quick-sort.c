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

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int nums[MAX], int low, int high) {
	int pivot = nums[high];
	int i = low-1;
	for (int j=low; j<high; j++) {
		if (nums[j]<=pivot) {
			i++;
			swap(&nums[i], &nums[j]);
		}
	}
	swap(&nums[i+1], &nums[high]);
	return (i+1);
}

void quickSort(int nums[MAX], int low, int high) {
	if (low<high) {
		int q = partition(nums, low, high);
		quickSort(nums, low, q-1);
		quickSort(nums, q+1, high);
	}
}

int main() {
	int nums[MAX], n;
	
	printf("How many elements do you want?\n");
	scanf("%d", &n);
	
	printf("\nEnter %d elements:\n", n);
	read(nums, n);
	
	printf("\nOriginal Array:\n");
	display(nums, n);
	
	quickSort(nums, 0, n-1);
	printf("\n\nSorted Array:\n");
	display(nums, n);
	
	return 0;
}
