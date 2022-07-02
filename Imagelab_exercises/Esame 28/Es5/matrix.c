#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"

void mat_create(struct matrix *m, size_t rows, size_t cols)
{
	m->rows = rows;
	m->cols = cols;
	m->data = malloc((rows*cols) * sizeof(double));
}

struct matrix *new_mat(size_t n,size_t rows, size_t cols)
{
	struct matrix *m = malloc(n*sizeof(struct matrix));

	for (size_t i = 0; i < n; i++)
	{
		mat_create(m, rows, cols);
	}
	
	return m;
}

double mat_get(const struct matrix *m, size_t r, size_t c)
{
	return m->data[m->cols*r + c];
}

void mat_set(struct matrix *m, size_t r, size_t c, double val)
{
	m->data[m->cols*r + c] = val;
}


struct matrix **leggi_matrici(const char *filename, size_t *size)
{
	FILE *f = fopen(filename, "rt");
	if (f == NULL)
	{
		*size = 0;
		return NULL;
	
	}
		
	else
	{
		int nMatrix = 0;
		fscanf(f, "%d", &nMatrix);
		if (nMatrix <= 0)
		{
			*size = 0;
			return NULL;
		}
		else
		{
			struct matrix **p = malloc(nMatrix);
			*size = (size_t)nMatrix;
			double tempo;
			for (size_t i = 0; i < nMatrix; i++)
			{
				size_t rows, cols;
				fscanf(f, "%u,%u", &rows, &cols);
				p[i] = malloc(sizeof(struct matrix));
				p[i]->cols = (size_t)cols;
				p[i]->rows = (size_t)rows;
				p[i]->data = malloc(p[i]->rows*p[i]->cols * sizeof(double) + 1);
				for (size_t x = 0; x < cols*rows; x++)
				{
					fscanf(f, ",%lf", &tempo);
					p[i]->data[x] = tempo;
				}
			}
			fclose(f);
			return p;
		}
			
		
	}
}