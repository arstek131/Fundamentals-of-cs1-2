#include "farfallino.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isVowel(char p)
{
	if (p == 'a' || p == 'A' || p == 'e' || p == 'E' || p == 'i' || p == 'I' || p == 'o' || p == 'O' || p == 'u' || p == 'U')
		return 1;
	else
		return 0;
}

char *farfallino_decode(const char *s)
{
	if (s == NULL)
		return NULL;
	else
	{
		size_t myCounter = strlen(s);
		
		for (size_t i = 0; i < strlen(s); i++)
		{
			if (isVowel(s[i]))
			{
				myCounter = myCounter - 2;
				i = i + 2;
			}

		}

		char *p = malloc((myCounter + 1) * sizeof(char));
		size_t j = 0;

		for (size_t i = 0; i < strlen(s); i++)
		{
			if (isVowel(s[i]))
			{
				p[j] = s[i];
				i = i + 2;
			}
			else
			{
				p[j] = s[i];
			}
			
			j++;

		}

		p[myCounter] = 0;

		return p;

	}
}