#include "lists.h"

/**
 * get_dnodeint_at_index - get n'th node of list
 * @head: header of list
 * @index: index of node from 0
 * Return: address of n'th node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *headcopy;
	unsigned int i;

	headcopy = head;
	if (headcopy != NULL)
	{
		while (headcopy->prev != NULL)
			headcopy = headcopy->prev;

		for (i = 0; (i < index) && (headcopy != NULL); i++)
			headcopy = headcopy->next;
		return (headcopy);
	}
	else
		return (NULL);
}
