#include "main.h"

int open_files(char *read_from, char *write_to);
int read_files(int from_fyl, int to_fyl, char *read_from, char *write_to);
int write_to_file(char *load, int to_fyl, int read_chars, char *write_to);

/**
 * main - Entry point
 * @argc: Count of the arguments to start the program.
 * @argv: An array of strings containing the arguments passed to the program.
 * Description: The overall goal of this program is to copy the contents of a
 * file READ_FILE to a file WRITE_FILE. Usage ./cp READ_FILE WRITE_FILE.
 * Return: Always zero, but It will have exit 97 when there it does not have
 * the right number of parameters, 98 when it can not read / open
 * the file READ_FILE, 99 when it can not open/write to the file WRITE_FILE and
 * 100 when it can not close the file descriptors.
 */
int main(int argc, char **argv)
{
	char *read_from;
	char *write_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp read_file write_file\n");
		exit(97);
	}
	read_from = argv[1];
	write_to = argv[2];

	open_files(read_from, write_to);
	exit(0);
	return (0);
}

/**
 * open_files - Opens the files necessary for copying contents.
 * @read_from: Name of the file read_file.
 * @write_to: Name of the file write_file.
 * Return: Always zero. Exit 98, and 99.
 */
int open_files(char *read_from, char *write_to)
{
	int from_fyl;
	int to_fyl;

	from_fyl = open(read_from, O_RDONLY);
	if (from_fyl == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", read_from);
		exit(98);
	}
	to_fyl = open(write_to, O_CREAT | O_EXCL | O_WRONLY, 0664);
	if (to_fyl == -1)
	{
		/*if (errno == EEXIST) was removed*/
		to_fyl = open(write_to, O_WRONLY | O_TRUNC);
		if (to_fyl == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", write_to);
			exit(99);
		}
	}
	read_files(from_fyl, to_fyl, read_from, write_to);
	if (close(from_fyl) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fyl);
		exit(100);
	}
	if (close(to_fyl) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_fyl);
		exit(100);
	}
	return (0);
}
/**
 * read_files - Reads the file FROM_FILE.
 * @from_fyl: File descriptor for FROM_FILE.
 * @to_fyl: File descriptor for TO_FILE.
 * @read_from: Name of the file read_file.
 * @write_to: Name of the file write_file.
 * Return: Always zero. Exit 98.
 */
int read_files(int from_fyl, int to_fyl, char *read_from, char *write_to)
{
	int read_chars;
	char load[1024];

	read_chars = read(from_fyl, load, 1024);
	if (read_chars == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", read_from);
		exit(98);
	}
	write_to_file(load, to_fyl, read_chars, write_to);
	while (read_chars != 0)
	{
		read_chars = read(from_fyl, load, 1024);
		if (read_chars == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", read_from);
			exit(98);
		}
		if (read_chars == 0)
			return (0);
		write_to_file(load, to_fyl, read_chars, write_to);
	}
	return (0);
}

/**
 * write_to_file - Writes to a file TO_FILE.
 * @load: An array of characters containing up to 1024 chars.
 * @to_fyl: File descriptor of file TO_FILE.
 * @read_chars: A number representing how many characters were read and need to
 * be written.
 * @write_to: Name of the file write_file.
 * Return: Always Zero. Exit 99.
 */
int write_to_file(char *load, int to_fyl, int read_chars, char *write_to)
{
	int i;

	for (i = 0; i < read_chars; i++)
	{
		if (write(to_fyl, &load[i], 1) == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", write_to);
			exit(99);
		}
	}
	return (0);
}
