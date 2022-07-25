#include "main.h"

/**
 * create_file - Function to create a file.
 * @filename: The name of the file to create.
 * @text_content: A string to write to the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int q;
	int y;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		text_content = "";

	q = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0600);
	if (q < 0)
	{
		if (errno == EEXIST)
		{
			q = open(filename, O_WRONLY | O_TRUNC);
			if (q == -1)
				return (-1);
		}
		else
			return (-1);
	}
	for (y = 0; text_content[y] != '\0'; y++)
	{
		if (write(q, &text_content[y], 1) == -1)
			return (-1);
	}
	close(q);
	return (1);
}
