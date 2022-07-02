#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int somma(int N)
{
	if (N != 0)
		return N + somma(N - 1);
	else
		return N;
}

int main()
{
	int N = 0;
	int ris = 0;
	printf("Inserisci N: ");
	scanf("%d", &N);

	 ris = somma(N);

	printf("\nLa somma e': %d\n", ris);

	return 0;
}