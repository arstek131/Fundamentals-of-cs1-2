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
extern bool isEmpty(list l);//TRUE se la lista è vuota, FALSE altrimenti
extern element head(list l);//Restituisce il primo elemento della lista 
extern list tail(list l);//Restituisce la coda della lista data


/******NONPRIMITIVE******/
extern void printElement(element el);//Stampa elemento di tipo el 
extern bool isLess(element e1, element e2);//Controlla se e1 < e2
extern bool isEqual(element e1, element e2);//Controlla se e1 == e2
extern element copy(element e1);//Copia l'elemento e lo ritorna
extern element getElement(void);//Esegue la scanf

extern void printList(list l);//Stampa tutta la lista
extern bool ricerca(element el, list l);//Ricerca di un elemento nella lista
extern int length(list l);//Restituisce la lunghzza della lista
extern int recurLength(list l);//(Ricorsiva)Restituisce la lunghzza della lista
extern void dealloc(list l);//Distruttore lista
extern list recurInsord(element e, list l);//(Ricorsiva)Inserimento ordinato in lista
extern list insord(element e, list l);//Inserimento ordinato in lista

extern list sort(list l);//Naive sort
extern void dup_delete(list l);//Rimuove i doppioni da una lista NON ORDINATA


extern element maxelement(list l);


#endif // LIST_H









