#define _CRT_SECURE_NO_WARNINGS
#include "leggi_linee.h"

char **leggi_linee(const char *filename)
{
	if (filename == NULL)
		return NULL;

	FILE *f = fopen(filename, "rt");
	if (f == NULL)
		return NULL;

	fseek(f, 0, SEEK_END);
	size_t l = ftell(f);
	if (l == 0)
	{
		fclose(f);
		char **k = NULL;
		return NULL;
	}

	rewind(f);

	char myArr[255];

	size_t counter = 0;

	while (fgets(myArr,255,f) !=NULL)
	{
		counter++;
	}

	char **p = calloc((counter+1) , sizeof(char*));

	rewind(f);

	for (size_t i = 0; i < counter; i++)
	{
		if (fgets(myArr, 255, f) == NULL)
		{
			break;
		}

		myArr[strcspn(myArr, "\n")] = 0;
		//printf("\n%s", myArr);
			p[i] = calloc(strlen(myArr)+1,sizeof(char));
			strcpy(p[i], myArr);
	
	}

	fclose(f);
	return p;




}