#include<stdio.h>
#define MAX 100

void read(int nums[MAX][MAX], int row, int col) {
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			printf("Enter nums[%d][%d]: ", i, j);
			scanf("%d", &nums[i][j]);
		}
	}
}

void display(int nums[MAX][MAX], int row, int col) {
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			printf("%d ", nums[i][j]);
		}
		printf("\n");
	}
}

void displayTranspose(int nums[MAX][MAX], int row, int col) {
	for (int j=0; j<col; j++) {
		for (int i=0; i<row; i++) {
			printf("%d ", nums[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int nums[MAX][MAX], row, col;
	
	printf("Enter the number of rows:\n");
	scanf("%d", &row);
	printf("Enter the number of columns:\n");
	scanf("%d", &col);
	
	printf("\n");
	read(nums, row, col);
	
	printf("\nOriginal matrix:\n");
	display(nums, row, col);
	
	printf("\n\nTransposed matrix:\n");
	displayTranspose(nums, row, col);
	
	return 0;
}
