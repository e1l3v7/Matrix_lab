#include "matrixelem.h"
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

void PrintMatrixElem(const MatrixElem* me) {
	for(size_t j = 0; j < me->size; j++) {
		printf("%d ",me->data[j]);
	}
	printf("\n");
}

MatrixElem* CreateMatrixElem(unsigned int size) {
	MatrixElem* me = (MatrixElem*)calloc(1, sizeof(MatrixElem));
	me->data = (int*)calloc(size, sizeof(int));
	me->size = size;
	return me;
}

void FreeMatrixElem(MatrixElem* me) {
	if(me->data != NULL) {
		free(me->data);
	}
}
