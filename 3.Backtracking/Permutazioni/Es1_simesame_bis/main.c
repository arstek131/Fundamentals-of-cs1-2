#include <stdio.h>

void paint(int n, int s, char zone[], char color[],int *num)
{
	int i;
	char tmp;
	if (s == n)
	{
		(*num)++;
		printf("(%d) ", *num);
		for (int i = 0; i < n; i++)
		{
			zone[i] = color[i];
		}
		zone[4] = zone[2];
		for (i = 0; i < n + 1; i++)
		{
			printf("%c ", zone[i]);
		}
		printf("\n");
		return;
	}

	for (i = s; i < n; i++)
	{
		tmp = color[s];
		color[s] = color[i];
		color[i] = tmp;
		paint(n, s + 1, zone, color, num);
		tmp = color[s];
		color[s] = color[i];
		color[i] = tmp;

	}

}



int main()
{
	char zone[5];//char array che rappresenta le 5 possibili zone
	char color[] = { 'r','v','b','g' }; //char array di colori che rappresenta i possibili colori
	int num = 0;
	printf("\n\n");
	paint(4,0,zone,color,&num);
	printf("\n\n");


	return 0;
}


