#include "heap.h"

int elecmp(const element * a, const element * b)
{
	if (a == b)
		return 0;
	else if (a > b)
		return -1;
	else
		return 1;
}

void swap(element *a, element *b)
{
	element temp = *a;
	*a = *b;
	*b = temp;
}

unsigned parent(unsigned i)
{
	return i / 2;
}

unsigned left(unsigned i)
{
	return 2 * i;
}

unsigned right(unsigned i)
{
	return 2 * i + 1;
}

element * createHeap()
{
	element *h = malloc(1 * sizeof(element));
	return h;
}

void MoveUp_MaxHeap(element * H, unsigned i, size_t heap_size)
{
	while (i != 1 && elecmp(&H[i], &H[parent(i)]) > 0) 
	{
		swap(&H[i], &H[parent(i)]);
		i = parent(i);
	}
}

void MoveUp_MaxHeap_Recursive(element * H, unsigned i, size_t heap_size)
{
	if (i == 1)
	{
		return; // I'm the root!
	}

	if (elecmp(&H[i], &H[parent(i)]) > 0) 
	{
		swap(&H[i], &H[parent(i)]);
		MoveUp_MaxHeap_Recursive(H, parent(i), heap_size);
	}
}

//Max-heapify
//Funzione che fa "rispettare" la proprietà che ogni nodo padre sia >= dei figli
void MoveDown_MaxHeap(element * H, unsigned i, size_t heap_size)
{
	unsigned l, r, largest = i;
	bool done;
	do {
		done = true;
		l = left(i);
		r = right(i);

		if ((l <= heap_size) && elecmp(&H[l], &H[largest]) > 0) 
		{
			largest = l;
		}

		if ((r <= heap_size) && elecmp(&H[r], &H[largest]) > 0) 
		{
			largest = r;
		}

		if (largest != i) 
		{
			swap(&H[i], &H[largest]);
			i = largest;
			done = false;
		}

	} while (!done);

}

//Max-heapify
//Funzione che fa "rispettare" la proprietà che ogni nodo padre sia >= dei figli
MoveDown_MaxHeap_Recursive(element * H, unsigned i, size_t heap_size)
{
	if (i > heap_size) 
	{
		abort();
	}

	unsigned l, r, largest = i;
	l = left(i);
	r = right(i);

	if ((l <= heap_size) && elecmp(&H[l], &H[largest]) == 1)
		largest = l;

	if ((r <= heap_size) && elecmp(&H[r], &H[largest]) == 1)
		largest = r;

	if (largest != i) 
	{
		swap(&H[i], &H[largest]);
		MoveDown_MaxHeap_Recursive(H, largest, heap_size);
	}
}

element FindMax_MaxHeap(element * H, size_t heap_size)
{
	if (heap_size < 1) 
	{
		abort();
	}

	return H[1];
}

element *Pop_MaxHeap(element * H, size_t * heap_size, element * popped)
{
	*popped = H[1];
	swap(&H[1], &H[*heap_size]);

	(*heap_size)--;
	MoveDown_MaxHeap_Recursive(H, 1, *heap_size);

	return realloc(H, (*heap_size + 1) * sizeof(element));
}

element * Push_MaxHeap(const element * new_e, element * H, size_t * heap_size)
{
	(*heap_size)++;
	H = realloc(H, (*heap_size + 1) * sizeof(element));
	H[*heap_size] = *new_e;

	MoveUp_MaxHeap(H, *heap_size, *heap_size);

	return H;
}



element GetElement()
{
	element el;
	printf("Inserisci l'elemento: ");
	scanf("%d", &el);
	return el;
}

void ShowElement(element el)
{
	printf("%d", el);
}

void PrintHeap(element *h, size_t heap_size)
{
	for (int i = 1; i <= heap_size; i++)
	{
		printf("\t%d", h[i]);
	}
}
