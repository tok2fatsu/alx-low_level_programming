#include "main.h"
#include <stdio.h>
/**
 * get_bit - Returns value at index
 * @n: Number to check the value
 * @index: The index to look for the number
 * Return: A value at a given index or -1 if an error occours
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int q;

	if (index > (sizeof(8) * 8))
		return (-1);
	/*repeating number to the right index*/
	for (q = 0; q < index; q++)
		n = n >> 1;
	return ((n & 1));
}
