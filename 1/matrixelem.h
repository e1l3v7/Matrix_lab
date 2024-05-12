#ifndef MATRIXELEM_H
#define MATRIXELEM_H

typedef struct
{
	int* data;
	int size; 
} MatrixElem;

MatrixElem* CreateMatrixElem(int size);
void PrintMatrixElem(MatrixElem* me);
void FreeMatrixElem(MatrixElem* me);

#endif