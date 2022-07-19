#include "lists.h"
listint_t *create_new_node(int n);
/**
 * insert_nodeint_at_index - Inserts a node at a given index
 * @head: Pointer to the first element
 * @idx: Index to insert a node at
 * @n: number to be inserted into the node
 * Return: The address of the newly created node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int l;
	listint_t *tmp_lst;
	listint_t *tmp_old;
	listint_t *nw_nd;

	tmp_lst = *head;
	if (head == NULL)
		return (NULL);
	nw_nd = create_new_node(n);
	if (nw_nd == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = nw_nd;
		return (nw_nd);
	}

	if (idx == 0)
		*head = nw_nd;
	for (l = 0; l < idx - 1 && tmp_lst != NULL && idx != 0; l++)
		tmp_lst = tmp_lst->next;
	if (tmp_lst == NULL)
		return (NULL);
	if (idx == 0)
		nw_nd->next = tmp_lst;
	else
	{
		tmp_old = tmp_lst->next;
		tmp_lst->next = nw_nd;
		nw_nd->next = tmp_old;
	}
	return (nw_nd);
}

/**
 * create_new_node - Creates a new node
 * @n: Value to add to the new node
 * Return: A pointer to a node
 */
listint_t *create_new_node(int n)
{
	listint_t *nw_nd;

	nw_nd = malloc(sizeof(listint_t));
	if (nw_nd == NULL)
		return (NULL);
	nw_nd->n = n;
	nw_nd->next = NULL;

	return (nw_nd);
}
