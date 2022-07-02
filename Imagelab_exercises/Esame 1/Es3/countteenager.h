#include <stdio.h>
#include <stdlib.h>


struct person {
	char name[256];
	unsigned int age;
};

extern unsigned int count_teenagers(FILE *f);