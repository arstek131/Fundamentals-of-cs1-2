#ifndef MATRIX_H
#define MATRIX_H
#endif // !MATRIX_h

#include <stdlib.h>
#include <stdio.h>

struct matrix {
	size_t rows, cols;
	double *data;
};

extern struct matrix *mat_rendiquadrata(const struct matrix *a);
extern int maxium(double a, double b);