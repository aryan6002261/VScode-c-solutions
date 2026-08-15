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

void mergeArray(int arr1[MAX], int arr2[MAX], int arr3[MAX], int n1, int n2, int *n3) {
	for (int i=0; i<n1; i++) {
		arr3[i] = arr1[i];
	}
	for (int i=0; i<n2; i++) {
		arr3[n1+i] = arr2[i];
	}
	*n3 = n1+n2;
}

int main() {
	int arr1[MAX], arr2[MAX], arr3[MAX], n1, n2, n3;
	
	printf("How many elements do you wantint first array?\n");
	scanf("%d", &n1);
	
	printf("\nEnter %d elements:\n", n1);
	read(arr1, n1);
	
	printf("\nHow many elements do you want in second array?\n");
	scanf("%d", &n2);
	
	printf("\nEnter %d elements:\n", n2);
	read(arr2, n2);
	
	printf("\nFirst Array:\n");
	display(arr1, n1);
	
	printf("\n\nSecond Array:\n");
	display(arr2, n2);

	mergeArray(arr1, arr2, arr3, n1, n2, &n3);
	
	printf("\n\nMerged Array:\n");
	display(arr3, n3);
	
	return 0;
}