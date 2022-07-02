#define _CRT_SECURE_NO_WARNINGS
#include "rational.h"

struct rational *rational_read(const char *filename, size_t *size)
{
	FILE *f = fopen(filename, "rt");

	if (f == NULL)
	{
		*size = 0;
		return NULL;
	}

	fseek(f, 0, SEEK_END);
	size_t dim = ftell(f);

	if (dim == 0)
	{
		*size = 0;
		fclose(f);
		return NULL;
	}

	rewind(f);
	int tmp1, tmp2, dimensione = 0;
	while (fscanf(f, "%d / %d ", &tmp1, &tmp2) == 2)
	{
		dimensione++;
	}

	rewind(f);
	struct rational *p = malloc(dimensione * sizeof(struct rational));
	size_t i = 0;
	while (fscanf(f, "%d / %d ", &tmp1, &tmp2) == 2)
	{
		p[i].num = tmp1;
		p[i].den = tmp2;
		i++;
	}

	*size = dimensione;
	fclose(f);
	return p;
}