#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;

typedef struct list_element{
	element value;
	struct list_element *next;
} item;

typedef item* list;

/******PRIMITIVE******/
extern list insertHead(element e, list l);//Costruisce una nuova lista aggiungendo in testa l'elemento passato
extern list emptyList();//Restituisce la lista vuota
extern bool IsEmpty(list l);//TRUE se la lista è vuota, FALSE altrimenti
extern element head(list l);//Restituisce il primo elemento della lista 
extern list tail(list l);//Restituisce la coda della lista data


/******NONPRIMITIVE******/
extern void printElement(element el);
extern void printList(list l);
extern bool ricerca(element el, list l);
extern list intersect (list l1, list l2);


#endif // LIST_H






