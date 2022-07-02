#ifndef MATRIX_H
#define MATRIX_H
#endif // !MATRIX_H

#include <stdlib.h>
#include <stdio.h>

struct matrix {
	size_t rows, cols;
	double *data;
};

extern struct matrix *mat_creatediag(const double *values, size_t n);