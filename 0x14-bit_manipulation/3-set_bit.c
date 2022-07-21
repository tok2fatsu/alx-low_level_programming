#include "main.h"
#include <stdio.h>

int set_bit(unsigned long int *n, unsigned int index)
/**
 * set_bit - Sets the value to 1 at index.
 * @n: Points to a number;
 * @index: index to replace
 * Return: 1 if it worked, or -1 if an error occurred
 */
{
	unsigned int rep;

	if (index > sizeof(unsigned int) * 8)
		return (-1);
	rep = 1;
	rep = rep << index;
	*n = ((*n) | rep);
	return (1);
}
