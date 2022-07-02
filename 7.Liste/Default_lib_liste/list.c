#include "list.h"

//***************Primitive

list insertHead(element e, list l)
{
	list t;
	t = (list)malloc(sizeof(item));
	t->value = e;
	t->next = l;
	return t;

}

list emptyList()
{
	return NULL;
}

bool isEmpty(list l)
{
	return (l == NULL);

}

element head(list l)
{
	if (isEmpty(l))
		abort();
	else
		return l->value;
}

list tail(list l)
{
	if (isEmpty(l))
		abort();
	else
		return l->next;
}

//**********Cominciano le NON primitive

void printElement(element el)
{
	printf("%d", el);
}

bool isLess(element e1, element e2)
{
	return (e1 < e2);
}

bool isEqual(element e1, element e2)
{
	return (e1 == e2);
}

element copy(element e1)
{
	element tmp;
	tmp = e1;
	return tmp;
}

element getElement(void)
{
	element el;
	scanf("%d", &el);
	return el;
}

void printList(list l)
{
	printf("[");
	while (!isEmpty(l))
	{
		printElement(head(l));
		l = tail(l);
		if (!isEmpty(l))
			printf(", ");
	}
	printf("]\n");
}

bool ricerca(element el, list l)
{
	bool trovato = false;

	while ((l != NULL) && !trovato)
	{
		if (l->value == el)
			trovato = true;
		else
			l = l->next;
	}

	return trovato;
}

int length(list l)
{
	int n = 0;
	while (!isEmpty(l))
	{
		n++;
		l = tail(l);
	}

	return n;
}

int recurLength(list l)
{
	if (isEmpty(l))
		return 0;
	else
		return 1 + recurLength(tail(l));
}

void dealloc(list l)
{
	list temp;
	while (!isEmpty(l))
	{
		temp = l;
		l = tail(l);
		free(temp);
	}
}

list recurInsord(element e, list l)
{
	list t;

	if (isEmpty(l) || !isLess(head(l), e))
	{
		t = insertHead(e, l);
		return t;
	}

	return insertHead(head(l), recurInsord(e, tail(l)));
}

list insord(element e, list l)
{
	list l1 = NULL, root = l;
	list t;

	if (isEmpty(l) || !isLess(head(l), e))
	{
		t = insertHead(e, l);
		return t;
	}

	t = insertHead(e, NULL);

	while (!isEmpty(l) && isLess(head(l), e))
	{
		l1 = l;
		l = tail(l);
	}

	l1->next = t;
	t->next = l;

	return root;

}


list sort(list l)
{
	if (isEmpty(l))
		return NULL;

	list tmp = l;
	list count;

	for (tmp = l; tmp->next != NULL; tmp = tmp->next)
	{
		for (count = tmp->next; count != NULL; count = count->next)
		{
			if (tmp->value > count->value)
			{
				element tempo = tmp->value;
				tmp->value = count->value;
				count->value = tempo;
			}
		}
	}

	return l;
}

void dup_delete(list l)
{
	list ptr2, dup;

	while (l != NULL)
	{
		list ptr = l;

		while (ptr->next != NULL)
		{
			if (l->value == ptr->next->value)
			{
				list tmp = ptr->next;
				ptr->next = tmp->next;
				free(tmp);
			}
			else
			{
				ptr = ptr->next;
			}
		}
		l = l->next;
	}
}

element maxelement(list l)
{
	element max = l->value;

	while (l != NULL)
	{
		if (l->value>max)
		{
			max = l->value;
		}

		l = l->next;
	}

	return max;
}


list insertTail(element e, list l)
{
	if (isEmpty(l)) {
		return insertHead(e, l);
	}

	list root = l, temp = 0;

	while (!isEmpty(l)) {
		temp = l;
		l = l->next;
	}

	temp->next = insertHead(e, l);

	return root;
}

list removeElement(element e, list l)
{
	if (l->value == e)
		return tail(l);

	list prev = l, current = l;
	while (!isEmpty(current) && current->value != e)
	{
		prev = current;
		current = current->next;
	}


	if (!isEmpty(current))
	{
		prev->next = current->next;
		free(current);
	}

	return l;


	
}
