#include "list.h"

int main()
{
	list l1=emptyList();
	char myFile[] = "voti.txt";
	l1=readFile(l1,myFile);
	printf("I voti memorizzati nel file '%s' sono: \n",myFile);
	printList(l1);
	printf("\nInserisci un valore soglia: ");
	int val;
	scanf("%d",&val);
	soglia(val,l1);
	
	return 0;
}


