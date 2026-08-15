#include<stdio.h>
#include <stdlib.h>
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

int findMax(int nums[MAX], int n) {
	int max = nums[0];
	for (int i=0; i<n; i++) {
		if (nums[i]>max) max = nums[i];
	}
	return max;
}

int* countingSort(int nums[MAX], int n) {
	int k = findMax(nums, n);
	int *count = (int*)calloc(k+1, sizeof(int));
	int *output = (int*)malloc(n * sizeof(int));
	
	// store count of each element in count array
	for (int i=0; i<n; i++) {
		count[nums[i]]++;
	}
	
	// change count array to hold running sum
	for (int i=1; i<=k; i++) {
		count[i] += count[i-1];
	}
	
	// build the output array
	for (int i=n-1; i>=0; i--) {
		output[count[nums[i]] - 1] = nums[i];
		count[nums[i]]--;
	}
	
	free(count);
	return output;
}

int main() {
	int nums[MAX], n;
	
	printf("How many elements do you want?\n");
	scanf("%d", &n);
	
	printf("\nEnter %d elements:\n", n);
	read(nums, n);
	
	printf("\nOriginal Array:\n");
	display(nums, n);
	
	int* output = countingSort(nums, n);
	printf("\n\nSorted Array:\n");
	display(output, n);
	
	return 0;
}
