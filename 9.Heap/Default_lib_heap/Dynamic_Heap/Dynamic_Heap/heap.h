#define _CRT_SECURE_NO_WARNINGS
#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef int element;

extern int elecmp(const element *a, const element *b);
extern void swap(element *a, element *b);
extern unsigned parent(unsigned i);
extern unsigned left(unsigned i);
extern unsigned right(unsigned i);

extern element *createHeap();// Crea una Heap vuota (la prima posizione non viene utilizzata, ovvero a[0])
extern element *Push_MaxHeap(const element *new_e, element *H, size_t *heap_size);// Aggiunge un nuovo elemeneto ad una coda MaxHeap e ripristina la priorità eseguento la MoveUp. La funzione restituisce poi il puntatore alla nuova MaxHeap

extern void MoveUp_MaxHeap(element *H, unsigned i, size_t heap_size);// MoveUp iterativa per una max heap 
extern void MoveUp_MaxHeap_Recursive(element *H, unsigned i, size_t heap_size);//MoveUp ricorsiva per un max heap
extern void MoveDown_MaxHeap(element *H, unsigned i, size_t heap_size);//MoveDown iterativa per una max heap 
extern MoveDown_MaxHeap_Recursive(element *H, unsigned i, size_t heap_size);// MoveDown ricorsiva per una max heap 

extern element FindMax_MaxHeap(element *H, size_t heap_size);// Restituisce il valore massimo di una MaxHeap senza eliminarlo dalla coda 
extern element *Pop_MaxHeap(element *H, size_t *heap_size, element *popped);//// Estrae l'elemento massimo da una coda MaxHeap (salvandolo in popped), lo scambia con l'ultimo valore della code e ripristina la priorità eseguento la MoveDown. La funzione restituisce poi il puntatore alla nuova coda MaxHeap

extern element GetElement();
extern void ShowElement(element el);
extern void PrintHeap(element *h, size_t heap_size);



#endif // !HEAP_H
