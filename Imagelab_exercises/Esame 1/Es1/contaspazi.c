#include "contaspazi.h"

unsigned int conta_spazi(const char *s)
{
	int counter = 0;

	for (size_t i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ')
			counter++;
	}

	return counter;
}