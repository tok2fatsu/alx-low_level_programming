#include "main.h"
/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
int fyl_rd, fyl_ryt, q, w, e;
char buf[BUFSIZ];

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
fyl_rd = open(argv[1], O_RDONLY);
if (fyl_rd < 0)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
fyl_ryt = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
while ((q = read(fyl_rd, buf, BUFSIZ)) > 0)
{
if (fyl_ryt < 0 || write(fyl_ryt, buf, q) != q)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(fyl_rd);
exit(99);
}
}
if (q < 0)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
w = close(fyl_rd);
e = close(fyl_ryt);
if (w < 0 || e < 0)
{
if (w < 0)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fyl_rd);
if (e < 0)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fyl_ryt);
exit(100);
}
return (0);
}
