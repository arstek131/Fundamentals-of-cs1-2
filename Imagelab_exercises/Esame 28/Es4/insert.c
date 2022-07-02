#include "insert.h"

char *inserisci(const char *str, const char *news, size_t indice)
{
	if (str == NULL || news == NULL)
		return NULL;
	if (indice > strlen(str))
		return NULL;

	char *tempo = calloc(strlen(str) + strlen(news) + 1, sizeof(char));
	size_t u = 0;
	for (size_t i = 0; i < strlen(str) + strlen(news); i++)
	{
	
		if (i == indice)
		{
			size_t j = indice;
			size_t k = 0;
			while (k < strlen(news))
			{
				tempo[j] = news[k];
				k++;
				j++;
				i++;
			}
		}

		tempo[i] = str[u];
			u++;
	}

	return tempo;
}