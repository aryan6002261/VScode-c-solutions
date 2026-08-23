#include<stdio.h>
#define MAX 100

void read(int matrix[MAX][MAX], int rows, int cols) {
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
}

void display(int matrix[MAX][MAX], int rows, int cols) {
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void transpose(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			result[j][i] = matrix[i][j];
		}
	}
}

int main() {
	int matrix[MAX][MAX], result[MAX][MAX];
	int rows, cols;

	printf("Enter the number of rows and columns:\n");
	scanf("%d %d", &rows, &cols);

	printf("\nEnter elements of the matrix:\n");
	read(matrix, rows, cols);

	printf("\nOriginal matrix:\n");
	display(matrix, rows, cols);

	transpose(matrix, result, rows, cols);

	printf("\nTranspose of matrix:\n");
	display(result, cols, rows);

	return 0;
}