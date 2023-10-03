#include "main.h"

/**
 * main - cp one file to another
 * @ac: arguments count
 * @av: array of pointers to string
 *
 * Return: 0 as exit status
 */
int main(int ac, char **av)
{
	char *from, *to;
	int fd_f, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	from = av[1];
	to = av[STDERR_FILENO];
	fd_f = open(from, O_RDONLY);
	if (fd_f < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
		exit(98);
	}
	fd_to = open(to, O_WRONLY | O_CREAT | O_TRUNC, 00664);
	if (fd_to < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
		exit(99);
	}
	read_write(from, to, fd_f, fd_to);
	if (!close_fd(fd_f) || !close_fd(fd_to))
		exit(100);
	return (0);
}
/**
 * read_write - read from file and write to anohter
 * @from: 1st file
 * @to: 2nd file
 * @fd_from: file from discriptor
 * @fd_to: file to discriptor
 */
void read_write(char *from, char *to, int fd_from, int fd_to)
{
	char buf[BUFFER];
	int count = read(fd_from, buf, BUFFER);

	if (count > 0)
	{
		if (write(fd_to, buf, count) < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
			exit(99);
		}
		read_write(from, to, fd_from, fd_to);
	}
	if (count < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
		close(fd_from);
		close(fd_to);

		exit(98);
	}
}
/**
 * close_fd - close file descriptor
 * @fd: file descriptor
 *
 * Return: 1 if close is success,
 * 0 otherwise.
 */
int close_fd(int fd)
{
	int flag = 1;
	int close_fd = close(fd);

	if (close_fd < 0)
	{
		flag = 0;
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	}
	return (flag);
}

