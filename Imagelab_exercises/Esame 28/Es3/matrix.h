#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>

struct matrix {
	size_t rows, cols;
	double *data;
};
extern struct matrix *rotate_v(const struct matrix *m,int n);
void mat_print(struct matrix *m, FILE *f);

#endif // !MATRIX_H





