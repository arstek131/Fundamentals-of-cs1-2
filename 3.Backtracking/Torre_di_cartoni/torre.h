#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned peso;
	unsigned altezza;
	unsigned limite;
}pacco;

typedef struct {
	unsigned altezza;
	int *pacchiTorre;
}torre;

void CostruisciTorre(int n, pacco *pacchi, int s, torre *corrente,  torre *best, int *listaUso);