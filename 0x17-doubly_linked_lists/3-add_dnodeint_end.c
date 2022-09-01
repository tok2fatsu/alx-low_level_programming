#include "lists.h"

/**
 * add_dnodeint_end -add a node at the start of list
 * @head: header of list
 * @n: number of node
 * Return: address of new node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *headcopy;

	headcopy = *head;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (*head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else
	{
		while (headcopy->next != NULL)
			headcopy = headcopy->next;
		new->next = NULL;
		new->prev = headcopy;
		headcopy->next = new;
	}

	return (new);
}
