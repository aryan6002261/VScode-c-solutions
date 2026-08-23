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

void merge(int nums1[], int n1, int nums2[], int n2, int nums3[]) {
	for (int i=0; i<n1; i++) {
		nums3[i] = nums1[i];
	}

	for (int i=0; i<n2; i++) {
		nums3[n1+i] = nums2[i];
	}
}

int main() {
	int nums1[MAX], nums2[MAX], nums3[MAX];
	int n1, n2;

	printf("How many elements do you want in the first array?\n");
	scanf("%d", &n1);

	printf("\nEnter %d elements:\n", n1);
	read(nums1, n1);

	printf("\nHow many elements do you want in the second array?\n");
	scanf("%d", &n2);

	printf("\nEnter %d elements:\n", n2);
	read(nums2, n2);

	printf("\nFirst array:\n");
	display(nums1, n1);

	printf("\n\nSecond array:\n");
	display(nums2, n2);

	merge(nums1, n1, nums2, n2, nums3);

	printf("\n\nMerged array:\n");
	display(nums3, n1+n2);

	return 0;
}