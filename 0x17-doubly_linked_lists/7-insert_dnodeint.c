#include "lists.h"

/**
  * insert_dnodeint_at_index -  inserts a new node
  * @h: header of of list
  * @idx: index of node from 0
  * @n: a given number
  * Return: address of n'th node
  */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *headcopy = *h;
	unsigned int i;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	while (headcopy != NULL && headcopy->prev != NULL)
	{
		headcopy = headcopy->prev;
		*h = (*h)->prev;
	}
	if (idx == 0)
	{
		free(new);
		return (add_dnodeint(h, n));
	}

	for (i = 0; (i < idx - 1) && headcopy != NULL; i++)
		headcopy = headcopy->next;
	if (headcopy == NULL)
	{
		free(new);
		return (NULL);
	}
	if (headcopy->next == NULL)
	{
		new->next = NULL;
		new->prev = headcopy;
		headcopy->next = new;
	} else
	{
		new->next = headcopy->next;
		new->prev = headcopy;
		headcopy->next->prev = new;
		headcopy->next = new;
	}
	return (new);
}
