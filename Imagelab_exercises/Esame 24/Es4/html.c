#define _CRT_SECURE_NO_WARNINGS

#include "html.h"

int rimuovi_html(const char *filein, const char *fileout)
{
	FILE *fi = fopen(filein, "rt");
	if (fi == NULL)
		return -1;
	FILE *fo = fopen(fileout, "wt");
	if (fo == NULL)
		return -1;
	
	fseek(fi, 0, SEEK_END);
	size_t dim = ftell(fi);
	if (dim == 0)
		return 0;
	else
	{
		rewind(fi);
		
		char myArr[255];
		size_t i = 0;
		while (i<10)
		{
			char *ret = fgets(myArr, 255, fi);
			size_t tmp = strlen(myArr);
			printf("\n%c\n", myArr[tmp-2]);
			i++;
		}
	}

}