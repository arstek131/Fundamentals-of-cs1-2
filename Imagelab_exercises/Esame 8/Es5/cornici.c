#include "cornici.h"

#include <stdio.h>
#include <stdlib.h>

void cornici(unsigned int n)
{
	int i = 0, j = 0;
	int t = 0, len = n;
	int flag = 0;

	if (len == 0)
		len = 1;
	else
		len += 3;

	for (i = 0; i<len; i++) {
		for (j = 0; j<len; j++)
		{
			if (i == j || j == len - i - 1)
				printf("+");
			else
				if (j != 0 && j != len - 1)
					if ((j<i && j<len - i) || (j>i && j>len - i - 1)) {
						printf("|");
					}
					else {
						printf("-");
					}

					if (j == len - 1 && i != 0 && i != len - 1)
						printf("|");
		}

		if (i<len - 2) {
			printf("\n|");
			flag = 1;
		}
		else
			printf("\n");
	}

	printf("\n");
	
}

