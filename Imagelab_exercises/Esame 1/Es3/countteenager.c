#define _CRT_SECURE_NO_WARNINGS
#include "countteenager.h"
#include <stdio.h>
#include <stdlib.h>

/*
struct person {
char name[256];
unsigned int age;
};
*/

unsigned int count_teenagers(FILE *f)
{
	struct person pp;

	int tot;
	fscanf(f, "%d", &tot);

	int counter = 0;

	while (fscanf(f, "%s %d", pp.name, &pp.age) == 2)
	{
		if (pp.age >= 13 && pp.age <= 19)
			counter++;
	}

	return counter;

}