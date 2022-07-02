#include "farfallino.h"

int main()
{
	char myString[] = "ciao";

	//printf("%d\n", strlen(myString));

	char *p = farfallino_encode(myString);

	return 0;
}