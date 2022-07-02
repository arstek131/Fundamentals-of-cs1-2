#define _CRT_SECURE_NO_WARNINGS
#include "parole.h"

int *valuesCount(unsigned int *i)
{
	int myValue = *i;
	int counter = 0;
	int k = 10;

	while (myValue / k>0)
	{
		k = k * 10;
		counter++;
	}

	int *p = malloc((counter + 1) * sizeof(unsigned int));

	int j = counter+1;
	while (j > 0)
	{
		j--;
		p[j] = myValue % 10;
		myValue = myValue / 10;
	}

	return p;
}
int dimensionCount(unsigned int *i)
{
	int myValue = *i;
	int counter = 0;
	int k = 10;

	while (myValue / k>0)
	{
		k = k * 10;
		counter++;
	}

	return counter + 1;
}

char *fun1_9(char *myArr, unsigned int *i)
{
	switch (*i)
	{
	case 1:
		myArr = "uno";
		break;
	case 2:
		myArr = "due";
		break;
	case 3:
		myArr = "tre";
		break;
	case 4:
		myArr = "quattro";
		break;
	case 5:
		myArr = "cinque";
		break;
	case 6:
		myArr = "sei";
		break;
	case 7:
		myArr = "sette";
		break;
	case 8:
		myArr = "otto";
		break;
	case 9:
		myArr = "nove";
		break;
	default:
		break;
	}

	return myArr;
}

char *fun10_19(char *myArr, unsigned int *i)
{
	switch (*i)
	{
	case 10:
		myArr = "dieci";
		break;
	case 11:
		myArr = "undici";
		break;
	case 12:
		myArr = "dodici";
		break;
	case 13:
		myArr = "tredici";
		break;
	case 14:
		myArr = "quattordici";
		break;
	case 15:
		myArr = "quindici";
		break;
	case 16:
		myArr = "sedici";
		break;
	case 17:
		myArr = "diciassette";
		break;
	case 18:
		myArr = "diciotto";
		break;
	case 19:
		myArr = "diciannove";
		break;
	default:
		break;
	}



	return myArr;
}

char *fun20_99(char *myArr, unsigned int *i)
{
	if ((*i % 10) == 0)
	{
		switch (*i)
		{
		case 20:
			myArr = "venti";
			break;
		case 30:
			myArr = "trenta";
			break;
		case 40:
			myArr = "quaranta";
			break;
		case 50:
			myArr = "cinquanta";
			break;
		case 60:
			myArr = "sessanta";
			break;
		case 70:
			myArr = "settanta";
			break;
		case 80:
			myArr = "ottanta";
			break;
		case 90:
			myArr = "novanta";
			break;
		default:
			break;
		}
	}
	else
	{
		int tmp = *i % 10;
		if (tmp == 1 || tmp == 8)
		{

		}
		else
		{
			int *tmp2 = valuesCount(&*i);
			int tmp3 = tmp2[0] * 10;
			char *tot = "0";
			tot=PrinciPalFun(tot, &tmp3);
			char *tot2 = "0";
			tot2=PrinciPalFun(tot2, &tmp);
			strcpy(myArr, strcat(tot, tot2));
		
		}
	}
	
	return myArr;
}

char *PrinciPalFun(char *sz, unsigned int *i)
{
	int *p = valuesCount(&*i);

	switch (dimensionCount(&*i))
	{
	//numero in unità (del tipo x)
	case 1:
		sz = fun1_9(sz, &*i);
		break;

	//numero in decine (del tipo xx)
	case 2:
		printf("sono in 2\n");
		if (*i >= 10 && *i <= 19)
			sz = fun10_19(sz, &*i);
		else
			sz = fun20_99(sz, &*i);
		break;

	//numero in centinaia(del tipo xxx)
	case 3:
		printf("sono in 3\n");
		if (*i == 100)
		{
			sz = "cento";
			break;
		}

		break;
	default:
		break;
	}

	return sz;
}

void a_parole_1_999(char *sz, unsigned int i)
{
	if (i < 1 || i>999)
	{
		sz[0] = 0;
	}
	
	sz=PrinciPalFun(*sz, &i);
	printf("\n%s", sz);
	
	
}