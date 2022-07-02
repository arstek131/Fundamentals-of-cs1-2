#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>
struct matrix {
	size_t rows, cols;
	double *data;
};

extern struct matrix **leggi_matrici(const char *filename, size_t *size);
#endif // !MATRIX_H
