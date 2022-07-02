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


struct matrix *prod_kronecker(const struct matrix *a, const struct matrix *b)
{
	if (a == NULL || b == NULL)
		return NULL;
	else
	{
		struct matrix *tmp = new_mat((a->rows*b->rows), (a->cols*b->cols));

		
		for (size_t rA=0; rA < a->rows; rA++)
		{
			for (size_t cA=0; cA < a->cols; cA++)
			{
				double first_a = mat_get(a, rA, cA);
				for (size_t rB=0; rB < b->rows; rB++)
				{
					for (size_t cB=0; cB < b->cols; cB++)
					{
						double first_b = mat_get(b, rB, cB);
						mat_set(tmp, (b->rows)*rA + rB, (b->cols)*cA + cB, first_a*first_b);
					}
				}
			}
		}

		return tmp;
	}

}