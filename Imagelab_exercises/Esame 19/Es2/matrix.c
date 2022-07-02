#include "matrix.h"

void mat_create(struct matrix *m, size_t rows, size_t cols)
{
	m->rows = rows;
	m->cols = cols;
	m->data = malloc((rows*cols) * sizeof(double));
}

struct matrix *new_mat(size_t rows, size_t cols)
{
	struct matrix *m = malloc(sizeof(struct matrix));

	mat_create(m, rows, cols);

	return m;
}

double mat_get(struct matrix *m, size_t r, size_t c)
{
	return m->data[m->cols*r + c];
}

void mat_set(struct matrix *m, size_t r, size_t c, double val)
{
	m->data[m->cols*r + c] = val;
}

void mat_zero(struct matrix *m)
{
	size_t rows = m->rows;
	size_t coloums = m->cols;

	size_t r;
	size_t c;

	for (r = 0; r<rows; ++r)
	{
		for (c = 0; c<coloums; ++c)
		{
			mat_set(m, r, c, 0.0);
		}
	}

}

struct matrix *mat_creatediag(const double *values, size_t n)
{
	if (n == 0)
	{
		struct matrix *tmp = new_mat(0, 0);
		return tmp;
	}
	else
	{
		struct matrix *tmp = new_mat(n, n);
		mat_zero(tmp);

		size_t rows = tmp->rows;
		size_t cols = tmp->cols;

		size_t r = 0;
		size_t c = 0;
		size_t i = 0;

		for (r = 0; r<rows; ++r)
		{
			for (c = 0; c<cols; ++c)
			{
				if (r == c)
				{
					mat_set(tmp, r, c, values[i]);
					i++;
				}
				
			}
		}

		return tmp;
		
	}

	
}