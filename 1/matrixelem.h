#ifndef MATRIXELEM_H
#define MATRIXELEM_H

typedef struct {
	int* data;
	unsigned int size; 
} MatrixElem;

MatrixElem* CreateMatrixElem(unsigned int size);
void PrintMatrixElem(const MatrixElem* me);
void FreeMatrixElem(MatrixElem* me);

#endif
