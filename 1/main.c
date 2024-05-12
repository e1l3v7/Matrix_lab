#include <stdio.h>
#include "matrixelem.h"
#include "lib-input.h"
#include "matrix.h"

int main(void) 
{
	int m;
	int flag = 1;
	printf("Введите количество строк матрицы: ");
	flag = Scanf(&m);
	if(flag == 0)
	{
		return 0;
	}
	Matrix* ma = CreateMatrix(m);	
	MatrixInput(ma);
	printf("\nМатрица:\n");
	PrintMatrix(ma);
	printf("\nВектор:\n");
	MatrixElem* v = count_unique(ma);
	PrintMatrixElem(v);
	FreeMatrix(ma);
}