#define _CRT_SECURE_NO_WARNINGS
#include "commaseparatedvalues.h"

double *read_csv(FILE *f, size_t *n)
{
	fseek(f, 0, SEEK_END);
	size_t k = ftell(f);
	if (k == 0)
	{
		n = 0;
		return NULL;
	}
	else
	{
		rewind(f);
		double tmp;
		size_t counter = 0;
		
		while (fscanf(f, " %lf\n,", &tmp) == 1)
		{
			counter++;
		}

		rewind(f);

		double *vector = malloc(counter * sizeof(double));
		size_t i = 0;

		while (fscanf(f, " %lf\n,", &tmp) == 1)
		{
			vector[i] = tmp;
			i++;
		}


		/*for (i = 0; i < counter; i++)
		{
			printf("%lf\n", vector[i]);
		}*/
		

		*n = counter;
		return vector;
		
	}
	
}