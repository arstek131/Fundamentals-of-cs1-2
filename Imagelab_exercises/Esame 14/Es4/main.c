#define _CRT_SECURE_NO_WARNINGS
#include "vettori.h"

int main()
{
	FILE *f = fopen("vettori1.log", "rt");
	if (f != NULL)
	{
		size_t *n;
		struct vettore *tmp = vettor_leggi(f, &n);
	}

	return 0;
}