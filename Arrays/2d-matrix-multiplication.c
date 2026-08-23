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

void multiply(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int matrix3[MAX][MAX], int r1, int c1, int c2) {
	for (int i=0; i<r1; i++) {
		for (int j=0; j<c2; j++) {
			matrix3[i][j] = 0;

			for (int k=0; k<c1; k++) {
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
}

int main() {
	int matrix1[MAX][MAX], matrix2[MAX][MAX], matrix3[MAX][MAX];
	int r1, c1, r2, c2;

	printf("Enter rows and columns of first matrix:\n");
	scanf("%d %d", &r1, &c1);

	printf("\nEnter rows and columns of second matrix:\n");
	scanf("%d %d", &r2, &c2);

	if (c1 != r2) {
		printf("\nMatrix multiplication is not possible.");
		return 0;
	}

	printf("\nEnter elements of first matrix:\n");
	read(matrix1, r1, c1);

	printf("\nEnter elements of second matrix:\n");
	read(matrix2, r2, c2);

	printf("\nFirst matrix:\n");
	display(matrix1, r1, c1);

	printf("\nSecond matrix:\n");
	display(matrix2, r2, c2);

	multiply(matrix1, matrix2, matrix3, r1, c1, c2);

	printf("\nMatrix after multiplication:\n");
	display(matrix3, r1, c2);

	return 0;
}