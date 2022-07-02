#define _CRT_SECURE_NO_WARNINGS
#include "conta.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

unsigned int contalettere(const char *nomefile)
{
	FILE *f = fopen(nomefile, "rt");
	if (f == NULL)
		return -1;
	else
	{
		unsigned int counter = 0;
		while (1)
		{
			int a = fgetc(f);
			if (a == EOF)
				break;
			if (isalpha(a))
			{
				counter++;
			}
		}

		flcose(f);
		return counter;
	}
}