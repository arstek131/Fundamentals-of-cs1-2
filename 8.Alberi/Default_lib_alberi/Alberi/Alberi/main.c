#include "tree.h"

int main()
{
	/*
	1) Chiedere se la funzione insOrdTree fa la stessa cosa della funzione insertBinOrd (ovvero inserimento ordinato nell'albero)
	2) Data una sequenza di valori (es numeri per livelli), costruire l'albero
	3) Passato un albero e un elemento, cercare ed eliminare tale elemento dall'albero
	5) Corregere deletElement()
	*/

	printf("\n\n");
	tree t1= emptyTree();

	/* BST che vogliamo creare
	     50
	  /       \
	 30       70
    /  \     /   \
   20   40  60   80 */

	

	t1 = insertBinOrd(50, t1);
	t1 = insertBinOrd(30, t1);
	t1 = insertBinOrd(20, t1);
	t1 = insertBinOrd(40, t1);
	t1 = insertBinOrd(70, t1);
	t1 = insertBinOrd(60, t1);
	t1 = insertBinOrd(80, t1);

	/*t1 = insertBinOrd(50, t1);
	t1 = insertBinOrd(30, t1);
	t1 = insertBinOrd(20, t1);
	t1 = insertBinOrd(5, t1);
	t1 = insertBinOrd(10, t1);
	t1 = insertBinOrd(60, t1);
	t1 = insertBinOrd(80, t1);*/

	preOrder(t1);//50 30 20 40 70 60 80
	printf("\n");
	inOrder(t1);//20 30 40 50 60 70 80
	printf("\n");
	postOrder(t1);//20 40 30 60 80 70 50
	printf("\n");
	inAmpiezza(t1);//50 30 70 20 40 60 80

	//printf("\n\nDominanti: %d", ContaDominanti(t1));
	printf("\n\nAAAAAAAAAAAA");
	printf("\n\nDominanti: %d", ContaDominanti(t1));
	printf("\n\n");
	structure(t1, 0);
	printf("\n\n");
	printf("ESAME: %d", SearchKey(t1, 900));
	
	return 0;
}