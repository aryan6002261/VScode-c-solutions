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

void selectionSort(int nums[MAX], int n) {
	for (int i=0; i<n-1; i++) {
		int min = i;
		for (int j=i+1; j<n; j++) {
			if (nums[min]>nums[j]) min = j;
		}
		if (min != i) {
		    int temp = nums[i];
		    nums[i] = nums[min];
		    nums[min] = temp;
		}
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
	
	selectionSort(nums, n);
	printf("\n\nSorted Array:\n");
	display(nums, n);
	
	return 0;
}
