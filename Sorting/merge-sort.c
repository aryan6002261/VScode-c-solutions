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

// merges two sorted sub-arrays: arr[left..mid] and arr[mid+1..right]
void merge(int nums[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
	// temporary arrays
	int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i=0; i<n1; i++) L[i] = arr[left + i];
    for (j=0; j<n2; j++) R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;
    while (i<n1 && j<n2) {
        arr[k++] = (L[i]<=R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    free(L);
    free(R);
}

// recursive Merge Sort function
void mergeSort(int nums[], int left, int right) {
    if (left < right) {
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
	
	mergeSort(nums, 0, n-1);
	printf("\n\nSorted Array:\n");
	display(nums, n);
	
	return 0;
}