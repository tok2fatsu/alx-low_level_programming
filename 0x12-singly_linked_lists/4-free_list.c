#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: head of linked list
 */
void free_list(list_t *head)
{
	list_t *crnt;
	list_t *nxt;

	crnt = head;

	while (crnt != NULL)
	{
		nxt = crnt->next;
		free(crnt->str);
		free(crnt);
		crnt = nxt;
	}
}
