/**
 * flip_bits - Returns the number of bits you would need to flip
 * @n: First number
 * @m: Second number
 * Return: the number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int out;
	unsigned long int read;

	out = n ^ m;
	for (read = 0; out > 0;)
	{
		if ((out & 1) == 1)
			read++;
		out = out >> 1;
	}

	return (read);
}
