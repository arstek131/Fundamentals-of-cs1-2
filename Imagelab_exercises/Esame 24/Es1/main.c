#include "dev_standard.h"

int main()
{
	double vec[] = { 3.22, 4.55, 6.21 };
	size_t dim = sizeof(vec) / sizeof(vec[0]);

	double res = calcola_dev(vec, dim);

	return 0;
}