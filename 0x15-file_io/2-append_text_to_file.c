#include "main.h"
/**
 * append_text_to_file - Appends text at the end of file.
 * @filename: Name of file.
 * @text_content: String to append at the end of file.
 * Return: 1 if file exist, -1 if file does not exist, or if
 * required permissions are not present.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int q;
	int y;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		return (1);
	q = open(filename, O_APPEND | O_WRONLY);
	if (q == -1)
		return (-1);
	for (y = 0; text_content[y] != '\0'; y++)
	{
		if (write(q, &text_content[y], 1) == -1)
		{
			close(q);
			return (-1);
		}
	}
	close(q);
	return (1);
}
