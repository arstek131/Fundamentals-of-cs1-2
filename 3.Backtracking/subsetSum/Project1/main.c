#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void funzione(int vec[], int n, int *cnt, int pos, int solCor[],int somma)
{
	//se sono una foglia cosa devo fare?
	//Significa che l'albero è pieno e vado a stampare
	if (somma == 31)
	{
		//riempio le caselle rimanenti del mio vettore soluzione corrente con 0
		for (int i = pos; i < n; i++)
		{
			solCor[i] = 0;
		}

		//vado a stampare la soluzione
		(*cnt)++;
		printf(" %d.)", *cnt);
		for (int i = 0; i < n; i++)
		{
			printf(" %d", solCor[i]);
		}
		printf("\n");

		//la foglia è finita, esco tornando al passo precedente
		return;
	}
	
	//tolgo il ramo inutile (in questo caso quando ho raggiunto la fine del mio array, la mia somma non fa 30)
	if (pos == n)
		return;
	
	//scendo l'albero considerando il caso in cui non prendo il pacco
	solCor[pos] = 0;
	//Scendo l'albero
	funzione(vec, n, cnt, pos + 1, solCor, somma);

	//somma dei pacchi presi fino ad ora + pacco in posizione [pos]
	int tmp = somma + vec[pos];//tmp usato in questo caso particolare (per comodità)

	//se posso scendo l'albero considerando il caso in cui prendo il pacco
	//pos==0 rappresenta se sono all'inizio del mio vettore soluzione corrente
	//la condizione principale data dal testo per prendere il pacco
	if (pos == 0 || (pos > 0 && tmp <= 31)) //al posto di tmp --> somma+vec[pos]
	{
		solCor[pos] = 1;
		funzione(vec, n, cnt, pos + 1, solCor, tmp);
	}
}

int main()
{
	int vec[4];//array di 5 pacchi


	int n = 4;//numero dei pacchi (dimensione array)

	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
	}

	int cnt = 0;//contatore delle soluzioni
	int pos = 0;
	int solCor[] = { 0,0,0,0,};//array contenente la soluzione corrente
	int somma = 0;

	funzione(vec, n, &cnt, pos, solCor,somma);


	
	return 0;
}