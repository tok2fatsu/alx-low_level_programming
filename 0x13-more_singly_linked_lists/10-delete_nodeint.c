#include "lists.h"
/**
 * delete_nodeint_at_index - Deletes a node at a designated index
 * @head: Pointer to the beginning of the list
 * @index: Index of the node to be freed
 * Return: 1 if susccessful, -1 if it fails
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int y;
	listint_t *tmp_lst;
	listint_t *nd;

	tmp_lst = *head;
	if (head == NULL || *head == NULL)
		return (-1);
	for (y = 0; y < index - 1 && tmp_lst != NULL && index != 0; y++)
		tmp_lst = tmp_lst->next;
	if (tmp_lst == NULL)
		return (-1);
	if (index == 0)
	{
		nd = tmp_lst->next;
		free(tmp_lst);
		*head = nd;
	}
	else
	{
		if (tmp_lst->next == NULL)
			nd = tmp_lst->next;
		else
			nd = tmp_lst->next->next;
		free(tmp_lst->next);
		tmp_lst->next = nd;
	}
	return (1);
}
