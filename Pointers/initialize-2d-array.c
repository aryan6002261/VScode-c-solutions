#include<stdio.h>
#include<stdlib.h>

void createArray(int*** nums, int row, int col) {
	*nums = (int**)malloc(row * sizeof(int*));
	for (int i=0; i<row; i++) {
		(*nums)[i] = (int*)malloc(col * sizeof(int));
	}
	
	printf("\nEnter %d elements:\n", row*col);
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			scanf("%d", &(*nums)[i][j]);
		}
	}
	
	printf("\nCreated Array:\n");
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			printf("%d ", (*nums)[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int row, col;
	int** nums;
	
	printf("How many rows and columns do you want?\n");
	scanf("%d%d", &row, &col);
	createArray(&nums, row, col);
	
	for (int i=0; i<row; i++) {
		free(nums[i]);
	}
	free(nums);
	return 0;
}