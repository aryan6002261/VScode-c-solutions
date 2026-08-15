#include<stdio.h>
#include<stdlib.h>

int** createArray(int row, int col) {
	int** output = (int**)malloc(row * sizeof(int*));
	for (int i=0; i<row; i++) {
		output[i] = (int*)malloc(col * sizeof(int));
	}
	
	printf("\nEnter %d elements:\n", row*col);
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			scanf("%d", &output[i][j]);
		}
	}
	
	printf("\nCreated Array:\n");
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			printf("%d ", output[i][j]);
		}
		printf("\n");
	}
	
	return output;
}

int main() {
	int row, col;
	
	printf("How many rows and columns do you want?\n");
	scanf("%d%d", &row, &col);
	int** nums = createArray(row, col);
	
	for (int i=0; i<row; i++) {
		free(nums[i]);
	}
	free(nums);
	return 0;
}