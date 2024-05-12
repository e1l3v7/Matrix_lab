#ifndef MATRIX_H
#define MATRIX_H
#include "matrixelem.h"

typedef struct
{
	MatrixElem* matrixelems;
	int rows;
} Matrix;

void AddToMatrix(Matrix* m,int size, int ind);
void PrintMatrix(Matrix* m);
Matrix* CreateMatrix(int rows);
void FreeMatrix(Matrix* m);
void MatrixInput(Matrix* m);
MatrixElem* count_unique(Matrix* m);

#endif