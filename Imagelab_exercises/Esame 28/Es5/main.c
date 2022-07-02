#include "matrix.h"

int main()
{
	size_t *dim = 0;

	struct matrix **p = leggi_matrici("file1.mats", &dim);

	return 0;
}