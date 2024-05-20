#include "matrix.h"
#include "lib-input.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int AddToMatrix(Matrix* m,unsigned int size, unsigned int ind) {
	MatrixElem* me = CreateMatrixElem(size);
	m->matrixelems[ind].size = size;
	m->matrixelems[ind].data = (int*)calloc(size,sizeof(int));	
	printf("\nВведите элементы строки: \n");
	for(size_t j = 0; j < size; j++) {
		int flag = Scanf(me->data+j);
		if(flag == 0) {
			FreeMatrixElem(me);
			free(me);
			return 0;
		}
	}
	memcpy(m->matrixelems[ind].data, me->data,size*sizeof(int));
	FreeMatrixElem(me);
	free(me);
	return 1;
}

int MatrixInput(Matrix* m) {
	int flag = 1;
	int n;
	for(size_t i = 0; i < m->rows; i++) {
		printf("\nВведите количество элементов в строке %ld: ", i + 1);
		flag = Scanf(&n);
		if(flag == 0) {
			return 0;
		}
		flag = AddToMatrix(m, n, i);
		if(flag == 0) {
			return 0;
		}
	}
	return 1;
}
void PrintMatrix(const Matrix* m) {
	for (size_t i = 0; i < m->rows; i++) {
		PrintMatrixElem(&m->matrixelems[i]);
	}
}

Matrix* CreateMatrix(unsigned int rows) {
	Matrix* m = (Matrix*)malloc(sizeof(Matrix));
	m->rows = rows;
	m->matrixelems = (MatrixElem*)calloc(rows, sizeof(MatrixElem));
	return m;
}

void FreeMatrix(Matrix* m) {
	for(size_t i = 0; i < m->rows; i++)
	{
		if(m->matrixelems+i) {
			FreeMatrixElem(m->matrixelems + i);
		}
	}
	free(m->matrixelems);
	free(m);
}

int count_unique_in_elem(const MatrixElem* me) {
	int not_unique = 0;
	for (size_t i = 0; i < me->size; i++) {     
		for (size_t j = 0; j < i; j++) {
			if(i != j && me->data[j] == me->data[i]) {       
				not_unique++; 
				break;
			}
		}
	}
	return me->size - not_unique;
}

void count_unique(const Matrix* m, MatrixElem* me) {
	for(size_t k = 0; k < m->rows; k++) {
		me->data[k] = count_unique_in_elem(m->matrixelems+k);
	}
	return;
}
