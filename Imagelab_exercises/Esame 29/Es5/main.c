#include "string_split.h"

int main()
{
	char *str = "alfabetizzazione";
	size_t index = 6; 
	char **s1=NULL;
	char **s2=NULL;

	string_split(str, index, &*s1, &*s2);

	return 0;
}