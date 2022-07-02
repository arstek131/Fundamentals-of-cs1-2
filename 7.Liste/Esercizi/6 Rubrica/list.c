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
	printf("\nInserisci il tuo nome: ");
	gets(e->nome);
	
	printf("\nInserisci il tuo cognome: ");
	gets(e->cognome);
	
	printf("\nInserisci il tuo indirizzo: ");
	gets(e->via);
	
	printf("\nInserisci il tuo numero: ");
	scanf("%d",&(e->numero));
}

bool isEmpty(list l)
{
	return (l==NULL);
	
}

void printElement(element el)
{
	printf("%s", el.via);
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

void ricerca(char *s, list l)
{
	bool trovato=false;
	
	while((l!=NULL)&& !trovato)
	{
		if(strcmp(s,l->value.via)==0)
			trovato=true;
		else
			l=l->next;
	}
	
	if(!trovato)
	{
		printf("\nIndirizzo non trovato\n");
	}
	else
	{
		printf("\nIndirizzo trovato e appartenente a: %s %s\n",l->value.nome,l->value.cognome);
	}
		
}


list elimIndirizzo(char *s, list l)
{
	
	list first = NULL;
	while(l != NULL)
	{
	    if(strcmp(s,l->value.via)==0)
	    {   //delete head
	       list temp = l;
	        l = l->next;
	        free(temp);
	    }
	    else
	    {   //delete head->next
	
	        if (first == NULL)
	            first = l;
	
	        if (l->next == NULL)
	            break;
	
	        if(strcmp(l->next->value.via,s)==0)
	        {
	            list temp = l->next;
	            l->next = l->next->next;
	            free(temp);
	        }
	        else
	            l = l->next;
	    }
	}
	
	return first;
		
}

int length(list l)
{
	int n=0;
	while(!isEmpty(l))
	{
		n++;
		l=tail(l);
	}
	
	return n;
}

list sort(list l)
{
	if(isEmpty(l))
		return NULL;
	
	list tmp=l;
	list count;
	
	for( tmp=l; tmp->next!=NULL; tmp=tmp->next)
	{
		for(count= tmp->next; count!=NULL; count=count->next)
		{
			
			if(strcmp(tmp->value.nome,count->value.nome)>0)
			{
				element tempo= tmp->value;
				tmp->value=count->value;
				count->value=tempo;
			}
		}
	}
		
	return l;
}
