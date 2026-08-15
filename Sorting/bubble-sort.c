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

void bubbleSort(int nums[MAX], int n) {
	for (int i=0; i<n-1; i++) {
		int flag = 0;
		for (int j=i+1; j<n; j++) {
			if (nums[i]>nums[j]) {
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				flag = 1;
			}
		}
		if (flag==0) break;
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
	
	bubbleSort(nums, n);
	printf("\n\nSorted Array:\n");
	display(nums, n);
	
	return 0;
}
