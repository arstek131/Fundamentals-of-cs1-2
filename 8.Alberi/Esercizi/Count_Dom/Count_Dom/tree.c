#include "tree.h"

void showEl(element a)
{
	printf(" %d", a);
}

bool isLess(element e1, element e2)
{
	if (e1 < e2)
		return true;
	else
		return false;
}

bool isEqual(element e1, element e2)
{
	if (e1 == e2)
		return true;
	else
		return false;
}

bool isEmpty(tree t)
{
	return (t == NULL);
}

tree emptyTree(void)
{
	return NULL;
}

element root(tree t)
{
	if (isEmpty(t))
		abort();
	else
		return t->value;
}

tree left(tree t)
{
	if (isEmpty(t))
		return NULL;
	else
		return t->left;
}

tree right(tree t)
{
	if (isEmpty(t))
		return NULL;
	else
		return t->right;
}

tree consTree(element e, tree l, tree r)
{
	/*costruisce un albero(binario), e sei tu che man mano devi
	indicare il figlio destro e il figlio sinistro.
	Ricorda che comincia a costruire dal basso, e in presenza di foglie
	gli ultimi 2 parametri sono emptytree()
	quando invece si tratta di un nodo, andiamo a specificare
	figlio destro a figlio sinistro.
	*/
	tree t = (node*)malloc(sizeof(node));
	t->value = e;
	t->left = l;
	t->right = r;
	return t;
}

tree insOrdTree(element e, tree t)
{
	if (isEmpty(t))
		return consTree(e, emptyTree(), emptyTree());
	else
	{
		if (isLess(e, root(t)) || isEqual(e, root(t)))
			return consTree(root(t), insOrdTree(e, left(t)), right(t));
		else
			return consTree(root(t), left(t), insOrdTree(e, right(t)));
	}
}

void preOrder(tree t)
{
	if (!isEmpty(t))
	{
		printf("\t");
		showEl(root(t));
		preOrder(left(t));
		preOrder(right(t));
	}
}

void inOrder(tree t)
{
	if (!isEmpty(t))
	{
		inOrder(left(t));
		printf("\t");
		showEl(root(t));
		inOrder(right(t));
	}
}

void postOrder(tree t)
{
	if (!isEmpty(t))
	{
		postOrder(left(t));
		postOrder(right(t));
		printf("\t");
		showEl(root(t));
	}
}

void inAmpiezza(tree t)
{
	int h = height(t);
	for (size_t i = 1; i <= h; i++)
	{
		printGivenLevel(t, i);
		printf("\n");
	}

}

void printGivenLevel(tree t, int lvl)
{
	if (isEmpty(t))
		return;
	if (lvl == 1)
	{
		showEl(t->value);
	}

	else if (lvl > 1)
	{
		printGivenLevel(t->left, lvl - 1);
		printGivenLevel(t->right, lvl - 1);
	}
}

bool memberTree(element e, tree t)
{
	if (isEmpty(t))
		return false;
	else
		if (isEqual(e, root(t)))
			return true;
		else
			if (isLess(e, root(t)))
				return memberTree(e, left(t));
			else
				return memberTree(e, right(t));

}

tree copy(tree t)
{
	return consTree(root(t), emptyTree(), emptyTree());
}

/*Passato alla funzione un BST e un elemento, la funzione
elimina l'elemento e ritorna la nuova radice
*/
tree deletElement(tree t, element e)
{
	if (isEmpty(t))
		return t;

	//se element da eliminare < dell'elemento in radice
	//allora sta nel sottoalbero di sinistra
	if (isLess(e, t->value))
		t->left = deletElement(t->left, e);

	//se element > dell'elemnto in radice
	//allora sta nel sottoalbero di destra
	else if (isLess(t->value, e))
		t->right = deletElement(t->right, e);

	//se element è == alla radice, allora è il nodo
	//da eliminare
	else
	{
		//nodo con solo un figlio o senza figli
		if (t->left == NULL)
		{
			tree tmp = t->right;
			free(t);
			return tmp;
		}
		else if (t->right == NULL)
		{
			tree tmp = t->left;
			free(t);
			return tmp;
		}

		tree tmp = findMin(t->right);
		t->value = tmp->value;
		t->right = deletElement(t->right, tmp->value);
	}
	return t;
}

void deleteTree(tree t)
{
	if (isEmpty(t))
		return;

	//Cominciamo ad eliminare i sottoalberi
	deleteTree(t->left);
	deleteTree(t->right);

	//elimina il singolo nodo..
	printf("\n Eliminazione nodo: %d", t->value);
	free(t);
}

tree findMin(tree t)
{
	tree current = t;
	while (t->left != NULL)
		current = current->left;

	return current;
}

tree insertBinOrd(element e, tree t)
{
	tree l = t;

	if (isEmpty(t))
		return consTree(e, emptyTree(), emptyTree());

	while (!isEmpty(t))
	{
		if (e <= root(t))
		{
			if (isEmpty(left(t)))
			{
				t->left = consTree(e, emptyTree(), emptyTree());
				t = left(t);
			}
			t = left(t);
		}
		else
		{
			if (isEmpty(t->right))
			{
				t->right = consTree(e, emptyTree(), emptyTree());
				t = right(t);
			}
			t = right(t);
		}
	}
	return l;
}

int countLeaf(tree t)
{
	if (isEmpty(t))
		return 0;
	else
	{
		if (t->left == NULL && t->right == NULL)
			return 1;
		else
			return countLeaf(t->left) + countLeaf(t->right);
	}
}

int ContaDiscendenti(tree t)
{
	if (isEmpty(t))
		return 0;
	else
		return (root(t) + ContaDiscendenti(t->left) + ContaDiscendenti(t->right));
}

bool isLeaf(tree t)
{
	if (t == NULL)
		return false;
	if (t->right == NULL && t->left == NULL)
		return true;
	return false;
}

int ContaDominanti(tree t)
{
	if (!isEmpty(t))
	{
		element r = 0, l = 0;

		if (!isEmpty(left(t)))
			l = root(left(t));

		if (!isEmpty(right(t)))
			r = root(right(t));

		if (root(t) >= r + l)
			return ContaDominanti(left(t)) + ContaDominanti(right(t));
	}
	
}

int height(tree t)
{
	if (isEmpty(t))
		return 0;
	else
	{
		int hl = height(left(t));
		int hr = height(right(t));
		if (hl > hr)
			return hl + 1;
		else
			return hr + 1;
	}
}
