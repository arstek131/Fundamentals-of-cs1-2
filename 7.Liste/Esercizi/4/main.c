#include "list.h"

int main()
{
	list l1=emptyList();
	int el;
	
	do
	{
		printf("\nInserisci un valore:\t");
		el=getElement();
		if(el>0)
		{
			l1=insertHead(el,l1);
		}
	}while(el!=0);
	
	printList(l1);
	printf("\nL'elemento massimo e': %d", maxelement(l1));
	dealloc(l1);

	
	
	return 0;
}


