#define _CRT_SECURE_NO_WARNINGS
#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //Dimensione massima array (array statico)

extern int left(int i);//formula figlio sinistro
extern int right(int i);//formula figlio destro
extern int Parent(int i);//formula nodo padre dato figlio (dx o sx)

extern void swap(int *n1, int *n2);

extern void MoveUp(int *A, int i, int heap_size);
extern void heapify(int *A, int i, int heap_size);
extern void buildHeap(int *A, int heap_size);
extern void heapSort(int *A, int dim);

extern int rimpiVett(int *A);
extern void rimpiVettPersonal(int *A, int n);
extern void stampaVett(int *A, int n);
extern void stampaVettTree(int *A, int n);

extern int getElement();



#endif // !HEAP_H
