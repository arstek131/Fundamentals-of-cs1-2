#include "string_split.h"

void string_split(const char *str, size_t index, char **s1, char **s2)
{
	if (str == NULL) 
	{
		*s1 = NULL;
		*s2 = NULL;
		return;
	}

	if (index > strlen(str))
	{
		*s1 = NULL;
		*s2 = NULL;
		return;
	}

	size_t counter = 0;
	int flag = 0;

	for (size_t i = 0; i < strlen(str); i++)
	{
		if (i == index || flag == 1)
		{
			flag = 1;
			counter++;
		}
	}
	
	//seconda stringa
	char *p = calloc(counter + 1, sizeof(char));

	size_t counter2 = strlen(str) - counter;

	//prima stringa
	char *p2 = calloc(counter2 + 1, sizeof(char));

	for (size_t i = 0; i < counter2; i++)
	{
		p2[i] = str[i];
	}

	flag = 0;
	size_t j = 0;

	for (size_t i = 0; i < strlen(str); i++)
	{
		if (i == index || flag == 1)
		{
			flag = 1;
			p[j] = str[i];
			j++;
		}
	}

	*s1 = p2;
	*s2 = p;

}