#include "main.h"
#include <stddef.h>
/**
 * clear_bit - sets the value of a bit to 0 at index.
 * @n: Points to a number
 * @index: Index to switch
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int rep;

	rep = 1;
	rep = rep << index;
	if (index > sizeof(unsigned long int) * 8 || n == NULL)
		return (-1);
	if (((*n >> index) & 1) == 1)
		*n = rep ^ *n;

	return (1);
}
