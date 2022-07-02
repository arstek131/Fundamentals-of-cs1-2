#define _CRT_SECURE_NO_WARNINGS
#include "readperson.h"

int main()
{
	char myFile[] = "person1.txt";
	FILE *f = fopen(myFile, "rt");
	if (f != NULL)
	{
		struct person pp;
		person_read(f, &pp);
	}


	return 0;
}