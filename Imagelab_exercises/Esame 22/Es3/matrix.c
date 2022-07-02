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

double mat_get(const struct matrix *m, size_t r, size_t c)
{
	return m->data[m->cols*r + c];
}

void mat_set(struct matrix *m, size_t r, size_t c, double val)
{
	m->data[m->cols*r + c] = val;
}

void mat_copy(const struct matrix *src, struct matrix *dst)
{
	size_t rows = dst->rows;
	size_t cols = dst->cols;

	size_t r = 0;
	size_t c = 0;

	for (r = 0; r<rows; ++r)
	{
		for (c = 0; c<cols; ++c)
		{
			double elem = mat_get(src, r, c);
			mat_set(dst, r, c, elem);
		}
	}
}

struct matrix *mat_clone(const struct matrix *src)
{
	struct matrix *dst = new_mat(src->rows, src->cols);
	mat_copy(src, dst);
	return dst;
}

struct matrix *matrix_flip_v(const struct matrix *m)
{
	if (m == NULL)
	{
		return NULL;
	}
	else
	{
		struct matrix *tmp = mat_clone(m);

		size_t rows = tmp->rows-1;
		size_t cols = tmp->cols;


		for (size_ t c = 0; c<cols; ++c)
		{
			size_t j = 0;
			for (size_ t r = 0; r<rows; ++r)
			{
				double tempo = mat_get(m, rows-j, c);
				mat_set(tmp, rows-j, c, mat_get(m, r, c));
				mat_set(tmp, r, c, tempo);
				j++;
			}

		}
		return tmp;
	}
	
}
