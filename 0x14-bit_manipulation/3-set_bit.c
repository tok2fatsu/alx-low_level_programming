/**
 * set_bit - Sets the value to 1 at a given index.
 * @n: Points to a number;
 * @index: index to replace
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int rep;

	if (index > sizeof(unsigned int) * 8)
		return (-1);
	rep = 1;
	rep = rep << index;
	*n = ((*n) | rep);
	return (1);
}
