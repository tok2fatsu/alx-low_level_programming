#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a node.
 * @h: Pointer to a pointer to the first node on a linked list.
 * @idx: Place for node to be inserted.
 * @n: Number in the node.
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *rep;
	dlistint_t *new;
	unsigned int counter;

	if (h == NULL || (*h == NULL && idx != 0))
		return (NULL);
	new = create_node(n);
	if (new == NULL)
		return (NULL);
	rep = *h;
	if (idx == 0)
	{
		if (*h == NULL)
			*h = new;
		else
		{
			new->next = rep;
			rep->prev = new;
			*h = new;
		}
		return (new);
	}
	for (counter = 0; rep->next != NULL || counter + 1 == idx; counter++)
	{
		if (counter + 1 == idx)
		{
			if (rep->next != NULL)
				rep->next->prev = new;
			new->next = rep->next;
			rep->next = new;
			new->prev = rep;
			return (new);
		}
		rep = rep->next;
	}
	free(new);
	return (NULL);
}
