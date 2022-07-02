#include "dev_standard.h"

double calcola_med(const double *vec, size_t size)
{
	double sum = 0;

	for (size_t i = 0; i < size; i++)
	{
		sum = sum + vec[i];
	}

	return sum / size;
}

double calcola_dev(const double *vec, size_t size)
{
	double med = calcola_med(vec, size);
	
	double tmp = 0;

	for (size_t i = 0; i < size; i++)
	{
		tmp = tmp+ pow(vec[i] - med, 2);
	}

	tmp = tmp / size;
	tmp = sqrt(tmp);

	return tmp;

}