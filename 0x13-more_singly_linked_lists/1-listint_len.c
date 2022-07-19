#include "lists.h"

/**
 * listint_len - Calculates the length of a list in a file
 * @h: Pointer to the begining of the list
 * Return: Returns the amount of nodes
 */
size_t listint_len(const listint_t *h)
{
	unsigned int cnt;

	if (h == NULL)
		return (0);
	for (cnt = 0; h != NULL; cnt++)
		h = h->next;
	return (cnt);
}
