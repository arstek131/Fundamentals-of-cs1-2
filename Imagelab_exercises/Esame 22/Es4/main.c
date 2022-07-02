#include "rational.h"

int main()
{
	char myFile[] = "file3.txt";
	size_t dim = 0;
	struct rational *p = rational_read(myFile, &dim);

	for (size_t i = 0; i < dim; i++)
	{
		printf("\n%d/%d", p[i].num, p[i].den);
	}

	return 0;
}