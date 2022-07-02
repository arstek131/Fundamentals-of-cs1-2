#include "heap.h"

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return 2*i+1;
}

int Parent(int i)
{
	return i / 2;
}

void swap(int * n1, int * n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

void MoveUp(int * A, int i, int heap_size)
{
	while (i != 1 && A[i] > A[Parent(i)])
	{
		swap(&A[i], &A[Parent(i)]);
		i = Parent(i);
	}
}

//Max-heapify
//Funzione che fa "rispettare" la proprietà che ogni nodo padre sia >= dei figli
void heapify(int * A, int i, int heap_size)
{
	int l, r, largest;
	l = left(i);
	r = right(i);

	largest = i;

	if (( l <= heap_size ) && ( A[l] > A[i] ))
		largest = l;

	if (( r <= heap_size ) && ( A[r] > A[largest] ))
		largest = r;


	if ( largest != i ) 
	{
		swap( &A[i], &A[largest] );
		heapify( A, largest, heap_size );
	}
}

void buildHeap(int * A, int heap_size)
{
	int i;

	for (i = heap_size / 2; i >= 1; i--)
	{
		heapify(A, i, heap_size);
	}
}

void heapSort(int * A, int dim)
{
	int i, heap_size;

	heap_size = dim;

	for (i = dim; i >= 2; i--) 
	{
		swap(&A[1], &A[i]);
		heapify(A, 1, --heap_size);
	}
	return;
}

int rimpiVett(int * A)
{
	int i;
	for (i = 1; i < MAX; i++)
	{
		A[i] = MAX - i;
	}
	
	return MAX - 1;
}

void rimpiVettPersonal(int *A, int n)
{
	for (int i = 1; i <= n; i++)
	{
		int e = getElement();
		A[i] = e;
	}
}

void stampaVett(int * A, int n)
{
	int i;
	printf("\n");
	for (i = 1; i <= n; i++)
	{
		printf(" %d", A[i]);
	}
}

void stampaVettTree(int *A, int n)
{
	int numToPrint = 1;
	int alreadyPrinted = 0;  // Count number of elements have been printed at this level 

	for (int i = 1; i <= n; i++) 
	{
		printf(" %d", A[i]);
		alreadyPrinted++;

		if (alreadyPrinted == numToPrint) 
		{
			printf("\n");
			numToPrint = numToPrint << 1;  // Double elements to print on next level
			alreadyPrinted = 0;  // Clear counter 
		}
	}
	printf("\n");
}



int getElement()
{
	int el;
	scanf("%d", &el);
	return el;
}

