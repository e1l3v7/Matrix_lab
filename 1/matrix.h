#ifndef MATRIX_H
#define MATRIX_H
#include "matrixelem.h"

typedef struct {
	MatrixElem* matrixelems;
	unsigned int rows;
} Matrix;

int AddToMatrix(Matrix* m,unsigned int size, unsigned int ind);
void PrintMatrix(const Matrix* m);
Matrix* CreateMatrix(unsigned int rows);
void FreeMatrix(Matrix* m);
int MatrixInput(Matrix* m);
void count_unique(const Matrix* m, MatrixElem* me);

#endif
