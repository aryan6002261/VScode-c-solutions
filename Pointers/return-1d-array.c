#include<stdio.h>
#include<stdlib.h>

int* createArray(int n) {
	int* output = (int*)malloc(n * sizeof(int));
	
	printf("\nEnter %d elements:\n", n);
	for (int i=0; i<n; i++) {
		scanf("%d", &output[i]);
	}
	
	printf("\nCreated Array:\n");
	for (int i=0; i<n; i++) {
		printf("%d ", output[i]);
	}
	
	return output;
}

int main() {
	int n;
	
	printf("How many elements do you want?\n");
	scanf("%d", &n);
	int* nums = createArray(n);
	
	free(nums);
	return 0;
}