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

int linearSearch(int nums[MAX], int n, int ele) {
	for (int i=0; i<n; i++) {
		if (nums[i]==ele) return i;
	}
	return -1;
}

int main() {
	int nums[MAX], n, ele, pos;
	
	printf("How many elements do you want?\n");
	scanf("%d", &n);
	
	printf("\nEnter %d elements:\n", n);
	read(nums, n);
	
	printf("\nArray created:\n");
	display(nums, n);
	
	printf("\n\nEnter the element to search:\n");
	scanf("%d", &ele);
	
	pos = linearSearch(nums, n, ele);
	
	(pos==-1) ? printf("\nElement not found") : printf("\nElement found at index %d", pos);
	
	return 0;
}
