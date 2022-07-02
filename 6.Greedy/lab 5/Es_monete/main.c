#include <stdio.h>
#include <stdint.h>


void check(int *mon, int b)
{
	int som = 0;
	size_t i = 0;
	int use[6] = { 0,0,0,0,0,0 };

	while (b != som)
	{
		if (mon[i] <= (b-som))
		{
			som = som + mon[i];
			use[i] = use[i] + 1;
		}
		else
		{
			i++;
		}
	}

	printf("\nPer raggiunger il budget di %d centesimi sono stati usati: \n", b);
	for (size_t i = 0; i < 6; i++)
	{
		if (use[i] != 0)
		{
			printf("\nPer il taglio %d sono state usate %d monete", mon[i], use[i]);
		}
	}
	printf("\n\n");
}

int main()
{
	int b;

	printf("Inserisci il budget: ");
	scanf("%d", &b);

	int mon[6] = { 50,20,10,5,2,1 };

	check(mon, b);

	return 0;
}