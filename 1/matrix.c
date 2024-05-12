#include "matrix.h"
#include "lib-input.h"
#include <stdlib.h>
#include <stdio.h>

void AddToMatrix(Matrix* m,int size,int ind)
{
	MatrixElem* me = CreateMatrixElem(size);
	printf("\nВведите элементы строки: \n");
	for(size_t j = 0; j < size; j++)
	{
		Scanf(&me->data[j]);
	}
	m->matrixelems[ind] = *me;
}
void MatrixInput(Matrix* m)
{
	int flag = 1;
	int n;
	for(size_t i = 0; i < m->rows; i++)
	{
		printf("\nВведите количество элементов в строке %ld: ", i + 1);
		flag = Scanf(&n);
		if(flag == 0)
		{
			return;
		}
		AddToMatrix(m, n, i);
	}

}
void PrintMatrix(Matrix* m)
{
	for (size_t i = 0; i < m->rows; i++)
	{
		PrintMatrixElem(&m->matrixelems[i]);
	}
}

Matrix* CreateMatrix(int rows)
{
	Matrix* m = (Matrix*)malloc(sizeof(Matrix));
	m->rows = rows;
	m->matrixelems = (MatrixElem*)malloc(rows * sizeof(MatrixElem));
	return m;
}

void FreeMatrix(Matrix* m)
{
	for (size_t i = 0; i < m->rows; i++)
	{
		FreeMatrixElem(&m->matrixelems[i]);
	}
	free(m->matrixelems);
	free(m);
}

MatrixElem* count_unique(Matrix* m)
{

	MatrixElem* v = CreateMatrixElem(m->rows);
	for(size_t k = 0; k < m->rows; k++)
	{
		int not_unique = 0;
		for (size_t i = 0; i < m->matrixelems[k].size; i++) 
		{     
			for (size_t j = 0; j < i; j++)
			{
				if(i != j && m->matrixelems[k].data[j] == m->matrixelems[k].data[i])
				{       
					not_unique++; 
					break;
				}
			}
		}
		v->data[k] = m->matrixelems[k].size - not_unique;
	}
	return v;
}