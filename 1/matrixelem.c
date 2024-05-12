#include "matrixelem.h"
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

void PrintMatrixElem(MatrixElem* me)
{
	for(size_t j = 0; j < me->size; j++)
	{
		printf("%d ",me->data[j]);
	}
	printf("\n");
}

MatrixElem* CreateMatrixElem(int size)
{
	MatrixElem* me = (MatrixElem*)malloc(sizeof(MatrixElem));
	me->data = (int*)malloc(size * sizeof(int));
	me->size = size;
	return me;
}

void FreeMatrixElem(MatrixElem* me)
{
	free(me->data);
	free(me);
}