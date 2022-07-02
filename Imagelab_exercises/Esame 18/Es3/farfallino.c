#include "farfallino.h"

#include<string.h>
#include <ctype.h>
#include <stdio.h>
#include<stdlib.h>

int isVowel(char p)
{
	if (p == 'a' || p == 'A' || p == 'e' || p == 'E' || p == 'i' || p == 'I' || p == 'o' || p == 'O' || p == 'u' || p == 'U')
		return 1;
	else
		return 0;
}

char *farfallino_encode(const char *s)
{
	int sumOut = 0;

	size_t i;

	for (i = 0; i < strlen(s); i++)
	{
		if (isVowel(s[i]))
		{
			sumOut = sumOut + 2;
		}
	}


	size_t newDim = 9;

	char *p = malloc((newDim + 1) * sizeof(char));

	size_t j = 0;

	p[newDim] = '\0';

	printf("%d\n", strlen(p));

	/*
	for (i = 0; i < newDim; i++)
	{
		if (isVowel(s[j]))
		{
			p[i] = s[j];
			p[i + 1] = 'f';
			p[i + 2] = s[j];
			i = i + 2;
		}
		else
		{
			p[i] = s[j];
		}
		j++;
	}

	*/

	//printf("%s\n", p);
	//printf("%d\n", strlen(p));
	return p;

}