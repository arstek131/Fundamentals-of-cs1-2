#define _CRT_SECURE_NO_WARNINGS
#include "capovolgi.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
	int t;

	t = *b;
	*b = *a;
	*a = t;
}

int capovolgi(const char *filein, const char *fileout)
{
	FILE *fi = fopen(filein, "rb");
	if (fi == NULL)
		return 0;
	FILE *fo = fopen(fileout, "wb");
	if (fo == NULL)
		return 0;

	fseek(fi, 0, SEEK_END);
	size_t dim = ftell(fi);

	if (dim == 0)
	{
		return 1;
	}
	else
	{
		rewind(fi);
		char *support = malloc(dim * sizeof(char));
		fread(support, sizeof(char), dim, fi);
		size_t len = dim;

		for (size_t i = 0; i <dim/2; i++)
		{
			len--;
			swap(&support[i], &support[len]);
		}

		fwrite(support, sizeof(char), dim, fo);
		free(support);
		fclose(fi);
		fclose(fo);
		return 1;

	}
	
}