#include <stdio.h>

void backTrack(int n, int s, int v[], int *num)
{
	if (s == n)
	{
		printf("%d ", (*num));
		(*num)++;
		for (int i = 0; i < n; i++)
		{
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		v[s] = i;
		backTrack(n, s + 1, v, num);
	}
}

int main()
{
	int n = 5;
	int v[5];
	int num = 0;
	int s = 0;

	backTrack(n, s, v, &num);

	return 0;
}