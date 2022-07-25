#include "main.h"
/**
 * read_textfile - Reads a file and prints it to the POSIX stdout.
 * @filename: The name of the file that needs to be read.
 * @letters: Is the number of letters the function should print.
 * Return: The actual number of letters it could read and print.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int q;
	int a;
	int read_alpha;
	char *load;

	if (filename == NULL)
		return (0);
	load = malloc(sizeof(char) * letters);
	if (load == NULL)
		return (0);
	q = open(filename, O_RDONLY);
	if (q == -1)
	{
		free(load);
		return (0);
	}

	read_alpha = read(q, load, letters);
	if (read_alpha == -1)
	{
		close(q);
		free(load);
		return (0);
	}

	for (a = 0; a < read_alpha; a++)
	{
		if (write(STDOUT_FILENO, &load[a], 1) == -1)
		{
			close(q);
			free(load);
			return (0);
		}

	}
	close(q);
	free(load);
	return (read_alpha);
}
