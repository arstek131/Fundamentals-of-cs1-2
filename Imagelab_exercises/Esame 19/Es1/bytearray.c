#include "bytearray.h"

uint8_t *absdiff(const uint8_t *a, const uint8_t *b, size_t n)
{
	if (n == 0)
		return NULL;
	else
	{
		uint8_t *p = malloc(n * sizeof(uint8_t));

		for (size_t i = 0; i < n; i++)
		{
			p[i] = abs(a[i] - b[i]);
		}

		return p;
	}
}