#include "list.h"

int main()
{
	list l1=emptyList();
	
	int i=0;
	
	do
	{
		//system("cls");
		printf("\n1)Inserisci un nuovo indirizzo.");
		printf("\n2)Stampa tutti gli indirizzi.");
		printf("\n3)Cerca un indirizzo");
		printf("\n4)Elimina un indirizzo");
		printf("\n5)Ordina indirizzi (in ordine alfabetico)");
		printf("\n0)Esci\n");
		
		scanf("%d",&i);
		fflush(stdin);
		
		switch(i)
		{
			case 1: {
					element k =insertData(&k);
					l1=insertHead(k,l1);
					break;
				    }
			case 2: {
					printList(l1);
					break;
				    }
			case 3: {
					 char tmp[20];
					 printf("\nInserisci la via da cercare: ");
					 gets(tmp);
					 ricerca(tmp,l1);
				     break;
			        }
			case 4: {
					 char tmp[20];
					 printf("\nInserisci la via da eliminare: ");
					 gets(tmp);
					 l1=elimIndirizzo(tmp,l1);
					 printList(l1);
				     break;
			        }
			case 5: {
					 l1=sort(l1);
					 printList(l1);
					 break;
					}
		}
		
		
	}while(i!=0);
	
	
	
	return 0;
}
