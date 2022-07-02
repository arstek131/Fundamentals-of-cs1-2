#define _CRT_SECURE_NO_WARNINGS
#include "libri.h"

struct libro *read_libri(const char *filename, unsigned int *pn)
{
	FILE *f = fopen(filename, "rt");
	if (f == NULL)
	{
		*pn = 0;
		return NULL;
	}
	else
	{
		fseek(f, 0, SEEK_END);
		size_t t = ftell(f);
		if (t == 0)
		{
			*pn = 0;
			return NULL;
		}
		else
		{
			rewind(f);
			size_t counter = 0;

		
			unsigned int codice;
			char titolo[255];
			unsigned int pagine;
			while (fscanf(f, "%d;%[^\;];%d", &codice, &titolo, &pagine) == 3)
			{
					counter++;
			}

			rewind(f);
			struct libro *tmp = malloc(counter * sizeof(struct libro));

			for (size_t i = 0; i < counter; i++)
			{
				fscanf(f, "%d;%[^\;];%d", &tmp[i].codice, &tmp[i].titolo, &tmp[i].pagine);

			}

			*pn = counter;
			fclose(f);
			return tmp;
		}
	}

}