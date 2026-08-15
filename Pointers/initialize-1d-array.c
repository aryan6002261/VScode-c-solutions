#include<stdio.h>
#include<stdlib.h>

void createArray(int** nums, int n) {
	*nums = (int*)malloc(n * sizeof(int));
	
	printf("\nEnter %d elements:\n", n);
	for (int i=0; i<n; i++) {
		scanf("%d", &(*nums)[i]);
	}
	
	printf("\nCreated Array:\n");
	for (int i=0; i<n; i++) {
		printf("%d ", (*nums)[i]);
	}
}

int main() {
	int n;
	int* nums;
	
	printf("How many elements do you want?\n");
	scanf("%d", &n);
	createArray(&nums, n);
	
	free(nums);
	return 0;
}