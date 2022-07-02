#include "list.h"

list insertHead(element e, list l)
{
	list t;
	t=(list)malloc(sizeof(item));
	t->value=e;
	t->next=l;
	return t;
	
}

list emptyList()
{
	return NULL;
}

element insertData(element *e)
{
	printf("\nInserisci nome prodotto: ");
	gets(e->nome);
	
	printf("\nInserisci quantita' prodotto: ");
	scanf("%d",&(e->qt));
	
	fflush(stdin);
	
	printf("\nInserisci unita' di misura: ");
	gets(e->unita);
	
	
}

bool ricerca(char *s, list l)
{
	bool trovato=false;
	
	while((l!=NULL)&& !trovato)
	{
		if(strcmp(s,l->value.nome)==0)
			trovato=true;
		else
			l=l->next;
	}
	
	if(!trovato)
		return true;
		
	return false;	
}

void ricercaMod(char *s, list l)
{
	bool trovato=false;
	
	while((l!=NULL)&& !trovato)
	{
		if(strcmp(s,l->value.nome)==0)
		{
			trovato=true;
			printf("\nQuantita': %d", l->value.qt);
			printf("\nUnita' di misura: %s\n", l->value.unita);
		}
		else
			l=l->next;
	}
	
	if(!trovato)
		printf("\nNessun elemento trovato!\n");		
}

bool isEmpty(list l)
{
	return (l==NULL);
	
}

element head(list l)
{
	if(isEmpty(l))
		abort();
	else
		return l->value;
}

list tail(list l)
{
	if(isEmpty(l))
		abort();
	else
		return l->next;
}

void printElement(element el)
{
	printf("%s", el.nome);
}

void printList(list l)
{
	printf("[");
	while(!isEmpty(l))
	{
		printElement(head(l));
		l=tail(l);
		if(!isEmpty(l))
			printf(", ");
	}
	printf("]\n");
}

void ricercaMod2(int x, list l)
{
	while(l!=NULL)
	{
		if(l->value.qt>=x)
		{
			printf("\n");
			printElement(l->value);
		}
		
		l=l->next;
	}
}

list insertTail(element e, list l)
{
	if (isEmpty(l)){
		return insertHead(e, l);
	}

	list root = l, temp = 0;

	while (!isEmpty(l)){
		temp = l;
		l = l->next;
	}

	temp->next = insertHead(e, l);

	return root;
}
