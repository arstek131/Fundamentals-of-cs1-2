#include "heap.h"

int main()
{
	/*
	int vettore[MAX];
	int n;
	int scelta;
	int el;
	char invio;

	n = rimpiVett(vettore);
	buildHeap(vettore, n);

	do {

		printf("\n\nMenu' Principale - CODA HEAP\n\nScegli l'operazione da eseguire: \n");
		printf("1. Inserisci elemento in coda\n");
		printf("2. Visualizza il prossimo elemento\n");
		printf("3. Servi il prossimo elemento\n");
		printf("0. Termina il programma\n");

		// acquisizione scelta utente
		scanf("%d", &scelta);
		scanf("%c", &invio);

		// interpretazione scelta ed esecuzione della relativa operazione

		switch (scelta) 
		{

		case 0:
			printf("Uscita dal programma\n");
			break;

		case 1:
			printf("Inserire il numero dell'elemento: ");
			el = getElement();
			n++;
			vettore[n] = el;
			MoveUp(vettore, n, n);
			break;

		case 2:
			printf("\nIl prossimo elemento e': %d", vettore[1]);
			break;

		case 3:
			printf("\nIl prossimo elemento e': %d (eliminato)", vettore[1]);
			vettore[1] = vettore[n];
			n--;
			heapify(vettore, 1, n);
			break;

		default:
			printf("la scelta non e' corretta, inserirne un'altra\n");
		}
	} while (scelta != 0);

	heapSort(vettore, n);

	stampaVett(vettore, n);
	*/

	
	int vettore[MAX];
	int n=MAX-1; /*numero di elementi*/


	
	
	//n = rimpiVett(vettore);
	rimpiVettPersonal(vettore, n);
	
	buildHeap(vettore, n);

	heapSort(vettore, n);
	
	

	printf("\n");
	stampaVettTree(vettore,n);
	
	
	getchar();

	return 0;

}