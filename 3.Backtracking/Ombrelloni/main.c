#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//N = numero n degli ombrelloni in prima fila (messo a 10 nel main)
//s = posizione corrente (a che livello dell'albero siamo)
//vec = vettore con valori 0 e 1 dove 1 = posizionato 0 = NON posizionato
//sol = numero delle soluzioni trovate
//counter = contatore dei ragazzi che sono stati posizionati fino ad ora nella soluzione corrente
//r= numero dei ragazzi da posizionare (3 in questo caso)

void OmbrSubset(int N, int s, int vec[], int *sol, int counter, int r)
{

	int i = 0;
	/*
	Controllo se la soluzione è completa (ho già posizionato i r ragazzi)
	*/
	if (counter == r)
	{
		printf("%d--> ", *sol);
		(*sol)++;
		//Completo il vec con la soluzione attuale 
		for (i = s; i < N; i++)
		{
			vec[i] = 0;
		}

		//stampo la soluzione corrente
		for (i = 0; i < N; i++)
		{
			printf("%d ", vec[i]);
		}

		printf("\n");
			
		return;

	}

	//La posizione corrente ha raggiunto la dimensione del vettore e la soluzione non è accettabile 
	if (s == N)
		return;

	//Continuo col backtrack senza posizionare nessun ragazzino 
	vec[s] = 0;
	OmbrSubset(N, s + 1, vec, sol, counter, r);

	//Se la condizione è verificata continuo il backtrack posizionando 1 ragazzo
	if (s == 0 || (s > 0 && vec[s - 1] == 0))
	{
		counter++;
		vec[s] = 1;
		OmbrSubset(N, s + 1, vec, sol, counter, r);
	}

}

int main()
{
	int N = 20;
	int r = 10;

	int sol = 0;

	int *vec = malloc(N * sizeof(int));

	//recursive function call
	OmbrSubset(N, 0, vec, &sol, 0, r);

	printf("\nThe number of solutions found is: %d\n", sol);

	free(vec);

	return 0;
}