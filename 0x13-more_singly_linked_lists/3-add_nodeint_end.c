#include "lists.h"
listint_t *create_node(const int n);

/**
 * add_nodeint_end - Adds a node at the end of a list of a file
 * @head: Pointer to the beginning of a list
 * @n: number to add to the node
 * Return: A pointer to the beginning of the list
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *nw_nd;
	listint_t *tmp;

	tmp = *head;
	if (head == NULL)
		return (NULL);

	nw_nd = create_node(n);
	if (nw_nd == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = nw_nd;
		return (*head);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = nw_nd;

	return (*head);
}

/**
 * create_node - Creates a node
 * @n: Value for the node
 * Return: A pointer to the beginning of the list
 */
listint_t *create_node(const int n)
{
	listint_t *nw_nd;

	nw_nd = malloc(sizeof(listint_t));
	if (nw_nd == NULL)
		return (NULL);
	nw_nd->n = n;
	nw_nd->next = NULL;

	return (nw_nd);
}
