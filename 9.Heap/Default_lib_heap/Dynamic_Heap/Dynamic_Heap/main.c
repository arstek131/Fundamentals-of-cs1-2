#include "heap.h"

int main()
{
	element *h = createHeap();
	size_t heap_size = 0; // numero di elementi nella heap

	unsigned scelta;
	element e;

	do
	{
		printf("\n\nMenu' Principale - CODA HEAP\n\nScegli l'operazione da eseguire: \n");
		printf("1. Inserisci elemento in coda\n");
		printf("2. Visualizza il prossimo elemento\n");
		printf("3. Servi il prossimo elemento\n");
		printf("4. Visualizza coda heap\n");
		printf("0. Termina il programma\n");

		// acquisizione scelta utente
		scanf("%d", &scelta);

		switch (scelta)
		{
			case 0:
				printf("Uscita dal programma!\n");
				break;

			case 1:
				printf("INSERIMENTO DI UN NUOVO ELEMENTO \n");
				e = GetElement();
				h = Push_MaxHeap(&e, h, &heap_size);
				break;

			case 2:
				if (heap_size == 0) 
				{
					printf("Nessun elemento in coda!\n");
				}
				else 
				{
					printf("Il prossimo elemento e' (NON SERVITO):\n");
					ShowElement(FindMax_MaxHeap(h, heap_size));
				}
				break;

			case 3:
				if (heap_size == 0) 
				{
					printf("Nessun elemento in coda!\n");
				}
				else {
					printf("Il prossimo elemento e' (SERVITO):\n");
					h = Pop_MaxHeap(h, &heap_size, &e);
					ShowElement(e);
				}
				break;

			case 4:
				if (heap_size == 0) 
				{
					printf("Nessun elemento in coda!\n");
				}
				else 
				{
					PrintHeap(h, heap_size);
				}
				break;
		}

	} while (scelta != 0);

	return 0;
}