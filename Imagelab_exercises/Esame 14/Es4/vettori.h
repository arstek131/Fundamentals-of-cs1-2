#ifndef VETTORI_H
#define VETTORI_H
#endif // !VETTORI_H

#include <stdio.h>
#include <stdlib.h>

struct vettore {
	size_t len;
	int *data;
};

extern struct vettore *vettori_leggi(FILE *f, size_t *n);