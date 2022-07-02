#define _CRT_SECURE_NO_WARNINGS
#include "croce.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("tmp.txt", "w");
	if (f == NULL)
		return -1;
	else
	{
		size_t dim = 5;
		stampa_croce(f, dim);
	}


	return 0;
}