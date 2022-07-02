#define _CRT_SECURE_NO_WARNINGS
#include "commaseparatedvalues.h"

int main()
{
	FILE *f = fopen("secondo.txt", "rt");
	if (f != NULL)
	{
		size_t *n;
		double *p = read_csv(f, &n);
	}

	return 0;
}