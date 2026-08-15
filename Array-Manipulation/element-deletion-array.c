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

void remove(int nums[MAX], int *n, int pos) {
	if (pos<0 || pos>*n-1) return;
	for (int *ptr = nums+pos; ptr<=nums+*n-1; ptr++) {
		*ptr = *(ptr+1);
	}
	(*n)--;
}

int main() {
	int nums[MAX], pos, n;
	printf("How many elements do you want in the array?\n");
	scanf("%d", &n);
	
	printf("\nEnter %d elements:\n", n);
	read(nums, n);
	
	printf("\nOriginal array:\n");
	display(nums, n);
	
	printf("\n\nWhat position element do you want to delete?\n");
	scanf("%d", &pos);
	
	remove(nums, &n, pos);
	
	printf("\nNew array:\n");
	display(nums, n);
	
	return 0;
}
