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

int binarySearch(int nums[MAX], int ele, int low, int high) {
	if (low>high) return -1;
	int mid = (low+high)/2;
	if (nums[mid]==ele) return mid;
	else if (nums[mid]<ele) return binarySearch(nums, ele, mid+1, high);
	else return binarySearch(nums, ele, low, mid-1);
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
	
	pos = binarySearch(nums, ele, 0, n-1);
	
	(pos==-1) ? printf("\nElement not found") : printf("\nElement found at index %d", pos);
	
	return 0;
}
