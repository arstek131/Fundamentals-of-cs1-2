#define _CRT_SECURE_NO_WARNINGS
#include "binary.h"

char *decimal_to_binary(int n)
{
	char *p = calloc(9, sizeof(char));

	int quoziente = n;
	int i = 1;
	while (quoziente != 0)
	{
		p[i++] = quoziente % 2;
		quoziente = quoziente / 2;
	}

	
}

void stampa_binario(const char* filename_in, const char* filename_out)
{
	FILE *fi = fopen(filename_in, "rb");
	if (fi == NULL)
		return;
	FILE *fo = fopen(filename_out, "wt");
	if (fo == NULL)
		return;

	fseek(fi, 0, SEEK_END);
	size_t dim = ftell(fi);
	if (dim == 0)
	{
		fclose(fi);
		fclose(fo);
		return;
	}
	else
	{
		rewind(fi);
		char *support = malloc(dim* sizeof(char));
		char *tmp = malloc(100 * sizeof(char));
		fread(support, 1, dim, fi);
		size_t counter = 0;
		for (size_t i = 0; i < dim; i++)
		{
			if (counter == 8)
				fputc('\n', fo);
			fputs(decimal_to_binary(support[i]), fo);
			fputc(' ', fo);
			counter++;
		}

		free(support);
		free(tmp);
		fclose(fi);
		fclose(fo);
	}
}