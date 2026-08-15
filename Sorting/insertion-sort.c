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

void insertionSort(int nums[MAX], int n) {
	for (int i=0; i<n; i++) {
		int key = nums[i];
		int j = i-1;
		while (j>=0 && nums[j]>key) {
			nums[j+1] = nums[j];
			j--;
		}
		nums[j+1] = key;
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
	
	insertionSort(nums, n);
	printf("\n\nSorted Array:\n");
	display(nums, n);
	
	return 0;
}
