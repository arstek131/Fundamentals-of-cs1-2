#include "unici.h"

int cmpfunc(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int *unici(const int *vec, size_t size, size_t *newsize)
{
	if (size == 0)
		return NULL;

	qsort(vec, size, sizeof(int), cmpfunc);

	size_t count = 0;
	//{ 2, 4, 4, 5, 5, 5, 7, 9 };
	for (size_t i = 0; i < size; i++)
	{
		if (vec[i] == vec[i + 1])
			count++;
	}

	*newsize = size - count;
	int *tmp = malloc(*newsize * sizeof(int));

	size_t src;
	size_t dst;

	for (src = 0, dst = 0; src < size; src++)
	{
		if (src > 0 && vec[src] == vec[src - 1])
			continue;

		tmp[dst] = vec[src];
		dst++;
	}

}