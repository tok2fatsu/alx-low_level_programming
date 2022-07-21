#include <stdio.h>
/**
 * get_endianness - Checks the systems Byte order for falts
 * Return: Returns 0 if big endian 1 if little endian
 */
int get_endianness(void)
{
	int j;
	int big_or_small;

	j = 1;
	big_or_small = (int) (((char *)&j)[0]);
	return (big_or_small);
}
