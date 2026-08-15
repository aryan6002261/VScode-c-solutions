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

void countingSort(int nums[MAX], int n, int exp) {
	int count[10] = {0};
	int *output = (int*)malloc(n * sizeof(int));
	
	// store count of each element in count array
	for (int i = 0; i < n; i++) {
        int digit = (nums[i] / exp) % 10;
        count[digit]++;
    }
	
	// change count array to hold running sum
	for (int i=1; i<10; i++) {
		count[i] += count[i-1];
	}
	
	// build the output array
	for (int i = n - 1; i >= 0; i--) {
        int digit = (nums[i] / exp) % 10;
        output[count[digit] - 1] = nums[i];
        count[digit]--;
    }
	
	// Copy the sorted elements from the output array back to the original array
    for (int i = 0; i < n; i++) {
        nums[i] = output[i];
    }
    
	free(output);
}

void radixSort(int nums[MAX], int n) {
    int max = findMax(nums, n);

    // Call countingSort for every digit place value (1s, 10s, 100s, etc.)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(nums, n, exp);
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
	
	radixSort(nums, n);
	printf("\n\nSorted Array:\n");
	display(nums, n);
	
	return 0;
}