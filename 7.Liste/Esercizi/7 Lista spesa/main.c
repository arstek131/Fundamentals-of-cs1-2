#include "list.h"

int main()
{
	list l1=emptyList();
	int scelta;
	
	do
	{
		printf("\n\n1)Inserisci un elemento da acquistare (se e' gia' presente visualizzare un messaggio di errore).");
		printf("\n2)Inserisci un elemento da acquistare (in coda).");
		printf("\n3)Fornisci la quantita' e la relativa unita' di misura dato il nome dell'elemento da acquistare.");
		printf("\n4)Stampare tutti gli elementi da acquistare.");
		printf("\n5)Data una quantita', stampare gli elementi da acquistare che hanno quantita' strettamente maggiore.");
		printf("\n0)Esci\n");
		
		scanf("%d",&scelta);
		fflush(stdin);
		
		switch(scelta)
		{
			case 1:{
					element k =insertData(&k);
					bool tmp = ricerca(k.nome,l1);
					if(tmp)
					{
						l1=insertHead(k,l1);
					}
					else
					{
						printf("\nElemento gia' esistente nella lista.\n");
					}
					
				    break;
				   }
				   
			case 2:{
					
				    break;
			       } 
			       
			case 3:{
					char tmp[20];
					printf("\nInserisci il nome del prodotto: ");
					gets(tmp);
					ricercaMod(tmp,l1);
				    break;
			       } 
			       
			case 4:{
					printList(l1);
				    break;
			       } 
			       
			case 5:{
					int tmp;
					printf("\nInserisci la quantita' del prodotto: ");
					scanf("%d",&tmp);
					ricercaMod2(tmp,l1);
				    break;
			       } 
   
		}
		
		
	}while(scelta!=0);
	
	return 0;
}
