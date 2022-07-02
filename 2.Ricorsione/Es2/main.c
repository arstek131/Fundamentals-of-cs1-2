#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fib(int N)
{
	if (N < 2)
		return N;
	return fib(N - 2) + fib(N - 1);
}

int main()
{
	int N = 0;
	printf("Inserisci N-esimo elemento: ");
	scanf("%d", &N);

	int sum = fib(N);

	printf("N-esimo elemento e': %d\n", sum);

	return 0;
}