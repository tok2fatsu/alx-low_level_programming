#include "main.h"
#include <stdio.h>
/**
 * _atoi -starting point
 * @s: input
 * Return: always 0.
 */
int _atoi(char *s)
{
	int a = 1, b = 0;
	unsigned int num = 0;

for (b = 0; s[b] != '\0'; b++)
{
	if (s[b] == '-')
		a *= -1;
	else if (s[b] >= 0 + '0' && s[b] < 10 + '0')
		num = num * 10 + (s[b] - '0');
	else if (s[b - 1] >= 0 + '0' && s[b - 1] < 10 + '0')
		break;
}
return (num * a);
}
