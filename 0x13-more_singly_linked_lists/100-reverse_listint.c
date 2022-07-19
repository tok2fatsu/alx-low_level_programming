#include "lists.h"
/**
 * reverse_listint - Reverses a singly linked list
 * @head: pointer to the first element of the reversed list
 * Return: A pointer to the first element of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *tmp_lst;
	listint_t *nw_tmp_lst;

	if (head == NULL || *head == NULL)
		return (NULL);
	tmp_lst = *head;
	*head = tmp_lst->next;
	tmp_lst->next = NULL;

	while (1 && *head != NULL)
	{
		nw_tmp_lst = (*head)->next;
		(*head)->next = tmp_lst;
		tmp_lst = *head;
		if (nw_tmp_lst == NULL)
			return (*head);
		*head = nw_tmp_lst;
	}
	if (*head == NULL)
	{
		*head = tmp_lst;
		return (*head);
	}
	return (NULL);
}
