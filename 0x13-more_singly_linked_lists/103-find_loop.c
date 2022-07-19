#include "lists.h"

/**
 * find_listint_loop - Finds the loop contained in
 *                     a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: If there is no loop - NULL.
 *         Otherwise - the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *eli, *bun;

if (head == NULL || head->next == NULL)
return (NULL);

eli = head->next;
bun = (head->next)->next;

while (bun)
{
if (eli == bun)
{
eli = head;

while (eli != bun)
{
eli = eli->next;
bun = bun->next;
}

return (eli);
}

eli = eli->next;
bun = (bun->next)->next;
}

return (NULL);
}
