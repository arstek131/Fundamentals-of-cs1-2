#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	int CodArt;
	char Descrizione[40];
	char Tipologia[20];
}Articolo;

typedef struct {
	int CodFatt;
	char Data[11];
	char TipoPagamento[20];
	int IVA;
	char PIVA[16];
}Fattura;

typedef struct {
	int CodFatt;
	int NRiga;
	int CodArt;
	int Quantita;
	float PrezzoUnitario;
}RigaFattura;


#endif