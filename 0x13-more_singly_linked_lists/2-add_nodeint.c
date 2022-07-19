#include "lists.h"
/**
 * add_nodeint - Adds node at the beginning of the list of the file
 * @head: pointer to the beginning of the list
 * @n: number to add to a node
 * Return: A pointer to the head of the list
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *nw_nd;

	if (head == NULL)
		return (NULL);

	nw_nd = malloc(sizeof(listint_t));
	if (nw_nd == NULL)
		return (NULL);
	if (*head == NULL)
		nw_nd->next = NULL;
	else
		nw_nd->next = *head;
	nw_nd->n = n;
	*head = nw_nd;

	return (*head);
}
