#include <stdio.h>
/**
 * main - writes out the values
 * Description: avails the tru values out.
 * Return: prints out 1
 */
int main(void)
{
	FILE *fp;
	char str[] = "and that piece of art is useful - Dora Kopar, 2015-10-19";

	fp = fopen("file.txt", "w");
	fwrite(str, 2, sizeof(str), fp);
	fclose(fp);

	return (1);
}
