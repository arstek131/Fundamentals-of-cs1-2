#ifndef MATRIX_H
#define MATRIX_H
#endif // !MATRIX_H

#include <stdio.h>
#include <stdlib.h>

struct matrix {
	size_t rows, cols;
	double *data;
};

extern struct matrix *matrix_flip_v(const struct matrix *m);