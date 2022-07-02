#ifndef RATIONAL_H
#define RATIONAL_H
#endif // !RATIONAL_H

#include <stdlib.h>
#include <stdio.h>

struct rational {
	int num;
	unsigned int den;
};

extern struct rational *rational_read(const char *filename, size_t *size);