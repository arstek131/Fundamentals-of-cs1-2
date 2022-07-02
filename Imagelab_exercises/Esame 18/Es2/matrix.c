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

int maxium(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}


struct matrix *mat_rendiquadrata(const struct matrix *a)
{
	if (a->rows == a->cols)
	{
		struct matrix *tmp = mat_clone(a);
		return tmp;
	}
		
	else
	{
		struct matrix *tmp = new_mat(maxium(a->rows, a->cols), maxium(a->rows, a->cols));
		mat_zero(tmp);
		mat_copy(a, tmp);
		return tmp;
	}

}

