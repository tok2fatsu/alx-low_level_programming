#include "lists.h"
/**
 * get_nodeint_at_index - Returns the node at index
 * @head: Pointer to the first element
 * @index: Desired node at this position
 * Return: Pointer to desired node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int q;

	for (q = 0; q < index ; q++)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
