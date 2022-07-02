#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int element;

typedef struct treeElement {
	element value;
	struct treeElement *left, *right;
} node;

typedef node *tree;

//-----------------PRIMITIVE
extern void showEl(element a);//PRINT ELEMENT
extern bool isLess(element e1, element e2);
extern bool isEqual(element e1, element e2);

extern bool isEmpty(tree t);//CHECK IF IS EMPTY OR NOT
extern tree emptyTree(void);//RETURN AND EMPTY TREE
extern element root(tree t);//RETURN THE ROOT ELEMENT VALUE
extern tree left(tree t);//RETURN THE LEFT TREE
extern tree right(tree t);//RETURN THE RIGHT TREE
extern tree consTree(element e, tree l, tree r);//CONSTRUCT A NEW TREE(specifying left and right child)
extern tree insOrdTree(element e, tree t);//CONSTRUCT A NEW TREE ORDERED

										  //-----------------NON PRIMITIVE
extern void preOrder(tree t);//ORDINE ANTICIPATO
extern void inOrder(tree t);//IN ORDINE
extern void postOrder(tree t);//ORDINE POSTICIPATO
extern void inAmpiezza(tree t);//PER LIVELLI
extern void printGivenLevel(tree t, int lvl);//stampa per livelli

extern int height(tree t);//HEIGHT OF BST

extern bool memberTree(element e, tree t);//RICERCA DI UN ELEMENTO NELL'ALBERO

extern tree succ(tree t);
extern tree copy(tree t);//FUNCTION THAT COPY A TREE INTO ANOTHER TREE
extern tree deletElement(tree t, element e);//**********
extern void deleteTree(tree t);
extern tree findMin(tree t);//**************

extern tree insertBinOrd(element e, tree t);

extern int countLeaf(tree t);
extern int ContaDiscendenti(tree t);//passato un nodo, ritorna la somma di tutti i discendenti

extern int ContaDominanti(tree t);
//extern void visualizzaDiscendenti(tree t);//di ogni nodo dell'albero mi mostra la somma dei discendeti 


#endif

