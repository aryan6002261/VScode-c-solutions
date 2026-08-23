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

void add(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int matrix3[MAX][MAX], int rows, int cols) {
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}

int main() {
	int matrix1[MAX][MAX], matrix2[MAX][MAX], matrix3[MAX][MAX];
	int rows, cols;

	printf("Enter the number of rows and columns:\n");
	scanf("%d %d", &rows, &cols);

	printf("\nEnter elements of first matrix:\n");
	read(matrix1, rows, cols);

	printf("\nEnter elements of second matrix:\n");
	read(matrix2, rows, cols);

	printf("\nFirst matrix:\n");
	display(matrix1, rows, cols);

	printf("\nSecond matrix:\n");
	display(matrix2, rows, cols);

	add(matrix1, matrix2, matrix3, rows, cols);

	printf("\nMatrix after addition:\n");
	display(matrix3, rows, cols);

	return 0;
}