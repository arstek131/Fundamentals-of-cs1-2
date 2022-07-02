#define _CRT_SECURE_NO_WARNINGS
#include "vettori.h"

struct vettore *vettori_leggi(FILE *f, size_t *n)
{
	fseek(f, 0, SEEK_END);
	size_t dim = ftell(f);
	if (dim == 0)
	{
		*n = 0;
		return NULL;
	}
	else
	{
		rewind(f);
		char value = 0;
		size_t counter = 0;
		
		while (1)
		{
			value = fgetc(f);
			if (value == EOF)
				break;
			if (value == '\n')
				counter++;
		}

		rewind(f);

		struct vettore *vet = malloc(counter * sizeof(struct vettore));

		int valore = 0;
		for (size_t i = 0; i < counter; i++)
		{
			fscanf(f, "%d", &valore);
			vet[i].len = valore;
			vet[i].data = malloc(valore * sizeof(int));

			for (size_t j = 0; j < vet[i].len; j++)
			{
				fscanf(f, "%d ", &vet[i].data[j]);
			}
		}
		
		*n = counter;
		return vet;



	}


}