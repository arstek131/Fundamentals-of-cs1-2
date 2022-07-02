#ifndef LIBRI_H
#define LIBRI_H
#endif // !LIBRI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct libro {
	unsigned int codice;
	char titolo[255];
	unsigned int pagine;
};

extern struct libro *read_libri(const char *filename, unsigned int *pn);
