#include <stdio.h>
#include <limits.h>
#include "matrixelem.h"
#include "lib-input.h"
#include "matrix.h"
#include <stdlib.h>
int main(void) {
	int m;
	int flag = 1;
	printf("Введите количество строк матрицы: ");
	flag = Scanf(&m);
	if(flag == 0) {
		return 0;
	}
	Matrix* ma = CreateMatrix(m);
	MatrixElem* v = CreateMatrixElem(ma->rows);
	flag = MatrixInput(ma);
	if(flag == 0) {
		FreeMatrix(ma);
		FreeMatrixElem(v);
		free(v);
		return 0;
	}
	printf("\nМатрица:\n");
	PrintMatrix(ma);
	printf("\nВектор:\n");
	count_unique(ma,v);
	PrintMatrixElem(v);
	FreeMatrix(ma);
	FreeMatrixElem(v);
	free(v);
	return 0;

}

