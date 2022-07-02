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

void mat_print(struct matrix *m, FILE *f)
{
	size_t rows = m->rows;
	size_t coloums = m->cols;
	double *data = m->data;

	size_t r;
	size_t c;

	for (r = 0; r<rows; ++r)
	{
		for (c = 0; c<coloums; ++c)
		{
			//fprintf(f,"%10.3f ",data[cols*r+c]); 1 metodo
			//fprintf(f,"%10.3f ",mat_get(m,r,c)); //2 metodo

			double elem = m->data[coloums*r + c];//metodo salvando in elem
			fprintf(stdout, "%10.3f ", elem);
		}
		//fputs("",f);//mette un a capo dopo ogni riga che scrive
		fprintf(stdout, "\n"); //2 metodo sempre per andare a capo
						  //fputc('\n',f); 3 metodo
	}
}

size_t ricFun(size_t r, int n, size_t rows)
{
	size_t flag = 0;
	int q = r + n;
	int p = q - rows;
	while (p >= rows)
	{
		flag = 1;
		p = p - rows;
	}
	if (flag)
		return p;
	else
	return (r + n) - rows;
}


struct matrix *rotate_v(const struct matrix *m, int n)
{
	if (m == NULL)
		return NULL;
	struct matrix *tmp = mat_clone(m);


	for (size_t r = 0; r < m->rows; r++)
	{
		for (size_t c = 0; c < m->cols; c++)
		{
			if (n > 0)
			{
				if ((r + n) > (m->rows - 1))
				{
					size_t tempo = ricFun(r, n, m->rows);
					mat_set(tmp, tempo, c, mat_get(m, r, c));
				}
				else
				{
					mat_set(tmp, r + n, c, mat_get(m, r, c));
				}
			}
			else
			{
				if ((int)r - abs(n)<0)
				{
					int tempo = ((int)r - abs(n)) + (m->rows);
					mat_set(tmp, tempo, c, mat_get(m, r, c));
				}
				else
				{
					mat_set(tmp, r - abs(n), c, mat_get(m, r, c));
				}
			}
			
		}
	}

	return tmp;
}