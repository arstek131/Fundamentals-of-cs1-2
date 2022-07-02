#include "readperson.h"

void person_read(FILE *f, struct person *pp)
{
	char k=0;
	size_t i = 0;

	while (k != ' ')
	{
		if(k!=' ')
		{
			k = fgetc(f);
			pp->name[i] = k;
			i++;
		}
	}

	pp->name[i] = 0;


	printf("%c", 0);
	
	while((k=fgetc(f))!=EOF)
	{
		pp->age = k;
	}
}