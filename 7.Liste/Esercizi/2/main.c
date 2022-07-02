#include "list.h"

int main()
{
	list l1=emptyList();
	list l2=emptyList();
	int el;
	
	printf("\tPRIMA LISTA\t");
	do
	{
		printf("\nInserisci un valore:\t");
		scanf("%d",&el);
		if(el>0)
		{
			l1=insertHead(el,l1);
				
		}
	}while(el!=0);
	
	printList(l1);
	
	printf("\n\tSECONDA LISTA\t");
	do
	{
		printf("\nInserisci un valore:\t");
		scanf("%d",&el);
		if(el>0)
		{
			l2=insertHead(el,l2);
				
		}
	}while(el!=0);
	
	printList(l2);
	
	printf("\n\tTERZA LISTA(differenza)\t");
	list l3=emptyList();
	l3=difference(l1,l2);
	printList(l3);
	
	return 0;
}


