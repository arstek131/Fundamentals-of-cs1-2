#define _CRT_SECURE_NO_WARNINGS
#include "countteenager.h"

int main()
{
	char myFile[] = "people1.txt";
	FILE *f = fopen(myFile, "rt");
	if (f != NULL)
	{
		unsigned int res = count_teenagers(f);
	}
	
	return 0;
}