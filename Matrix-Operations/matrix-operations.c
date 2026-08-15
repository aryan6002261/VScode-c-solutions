#include<stdio.h>
#define MAX 100

void read(int mat[MAX][MAX], int row, int col) {
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			printf("Enter matrix[%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
}

void display(int mat[MAX][MAX], int row, int col) {
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

void addMatrix(int mat1[MAX][MAX], int mat2[MAX][MAX], int add[MAX][MAX], int row1, int row2, int col1, int col2) {
	if (row1!=row2 || col1!=col2) {
		printf("\nMatrix addition not possible\n");
		return;
	}
	
	for (int i=0; i<row1; i++) {
		for (int j=0; j<col1; j++) {
			add[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	
	printf("\nAddition of Matrices:\n");
	display(add, row1, col1);
}

void subMatrix(int mat1[MAX][MAX], int mat2[MAX][MAX], int sub[MAX][MAX], int row1, int row2, int col1, int col2) {
	if (row1!=row2 || col1!=col2) {
		printf("\nMatrix subtraction not possible\n");
		return;
	}
	
	for (int i=0; i<row1; i++) {
		for (int j=0; j<col1; j++) {
			sub[i][j] = mat1[i][j] - mat2[i][j];
		}
	}
	
	printf("\nSubtraction of Matrices:\n");
	display(sub, row1, col1);
}

void mulMatrix(int mat1[MAX][MAX], int mat2[MAX][MAX], int mul[MAX][MAX], int row1, int row2, int col1, int col2) {
	if (col1!=row2) {
		printf("\nMatrix multiplication not possible\n");
		return;
	}
	
	for (int i=0; i<row1; i++) {
		for (int j=0; j<col2; j++) {
			for (int k=0; k<col1; k++) {
				mul[i][j] += mat1[i][k]*mat2[k][j];
			}
		}
	}
	
	printf("\nMultiplication of Matrices:\n");
	display(mul, row1, col2);
}

int main() {
	int mat1[MAX][MAX], mat2[MAX][MAX], add[MAX][MAX], sub[MAX][MAX], mul[MAX][MAX], row1, col1, row2, col2;
	
	printf("Enter the number of rows in first matrix:\n");
	scanf("%d", &row1);
	printf("Enter the number of columns in first matrix:\n");
	scanf("%d", &col1);
	
	read(mat1, row1, col1);
	
	printf("\nEnter the number of rows in second matrix:\n");
	scanf("%d", &row2);
	printf("Enter the number of columns in second matrix:\n");
	scanf("%d", &col2);

	read(mat2, row2, col2);
	
	printf("\nFirst Matrix:\n");
	display(mat1, row1, col1);
	
	printf("\nSecond Matrix:\n");
	display(mat2, row2, col2);
	
	addMatrix(mat1, mat2, add, row1, row2, col1, col2);
	subMatrix(mat1, mat2, sub, row1, row2, col1, col2);
	mulMatrix(mat1, mat2, mul, row1, row2, col1, col2);
	
	return 0;
}
