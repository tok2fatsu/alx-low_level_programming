#include "lists.h"

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * looped_listint_count - Counts the number of unique nd
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nd in the list.
 */
size_t looped_listint_count(listint_t *head)
{
listint_t *eli, *bun;
size_t nd = 1;

if (head == NULL || head->next == NULL)
return (0);

eli = head->next;
bun = (head->next)->next;

while (bun)
{
if (eli == bun)
{
eli = head;
while (eli != bun)
{
nd++;
eli = eli->next;
bun = bun->next;
}

eli = eli->next;
while (eli != bun)
{
nd++;
eli = eli->next;
}

return (nd);
}

eli = eli->next;
bun = (bun->next)->next;
}

return (0);
}

/**
 * free_listint_safe - Frees a listint_t list safely (ie.
 *                     can free lists containing loops)
 * @h: A pointer to the address of
 *     the head of the listint_t list.
 *
 * Return: The size of the list freed.
 *
 * Description: The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *tmp_lst;
size_t nd, index;

nd = looped_listint_count(*h);

if (nd == 0)
{
for (; h != NULL && *h != NULL; nd++)
{
tmp_lst = (*h)->next;
free(*h);
*h = tmp_lst;
}
}

else
{
for (index = 0; index < nd; index++)
{
tmp_lst = (*h)->next;
free(*h);
*h = tmp_lst;
}

*h = NULL;
}

h = NULL;

return (nd);
}
