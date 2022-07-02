#include "list.h"

list emptyList()
{
	return NULL;
}

bool IsEmpty(list l)
{
	return (l==NULL);
	
}

element head(list l)
{
	if(IsEmpty(l))
		abort();
	else
		return l->value;
}

list tail(list l)
{
	if(IsEmpty(l))
		abort();
	else
		return l->next;
}

list insertHead(element e, list l)
{
	list t;
	t=(list)malloc(sizeof(item));
	t->value=e;
	t->next=l;
	return t;
	
}

void printElement(element el)
{
	printf("%d", el);
}

void printList(list l)
{
	printf("[");
	while(!IsEmpty(l))
	{
		printElement(head(l));
		l=tail(l);
		if(!IsEmpty(l))
			printf(", ");
	}
	printf("]\n");
}

bool ricerca(element el, list l)
{
	bool trovato=false;
	
	while((l!=NULL)&& !trovato)
	{
		if(l->value==el)
			trovato=true;
		else
			l=l->next;
	}
	
	return trovato;
}

list intersect (list l1, list l2)
{
	list l3=emptyList();
	
	while(l1!=NULL)
	{
		if(ricerca(l1->value,l2))
		{
			l3=insertHead(l1->value,l3);
		}
		
		l1=l1->next;
	}
	
	return l3;
}
