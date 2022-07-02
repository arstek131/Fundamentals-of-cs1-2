#include "libri.h"

int main()
{
	char *s = "libri1.txt";
	unsigned int *pn;

	struct libro *rc = read_libri(s, &pn);

	return 0;
}