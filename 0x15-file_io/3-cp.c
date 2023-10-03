#include "main.h"

/**
 * main - cp 2 files
 * @ac: arguments count
 * @av: array of pointers to string
 *
 * Return: 0 as exit status
 */
int main(int ac, char **av)
{
	char *from, *to, buf[BUFFER];
	int fd_f, fd_to, count;
	(void)count;
	(void)buf;

	if (ac != 3)
		dprintf(2, "Usage: cp file_from file_to\n"), exit(97);
	from = av[1];
	to = av[2];
	fd_f = open(from, O_RDONLY);
	if (fd_f < 0)
		dprintf(2, "Error: Can't read from file %s\n", from), exit(98);
	fd_to = open(to, O_WRONLY | O_CREAT | O_TRUNC, 00664);
	if (fd_to < 0)
		dprintf(2, "Error: Can't write to %s\n", to), exit(99);
#if 0
	while ((count = read(fd_f, buf, BUFFER)) > 0)
		if (write(fd_to, buf, count) != count)
		{
			dprintf(2, "Error: Can't write to %s\n", to);
			exit(99);
		}
	if (count < 0)
	{
		dprintf(2, "Error: Can't read from file %s\n", from);
		exit(98);
	}
#endif
	read_write(from, to, fd_f, fd_to);
	if (close(fd_f) < 0)
	{
		dprintf(2, "Error: Can't close fd %i\n", fd_f);
		exit(100);
	}
	if (close(fd_to) < 0)
	{
		dprintf(2, "Error: Can't close fd %i\n", fd_to);
		exit(100);
	}
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
			dprintf(2, "Error: Can't write to %s\n", to);
			exit(99);
		}
		read_write(from, to, fd_from, fd_to);
	}
	if (count < 0)
	{
		dprintf(2, "Error: Can't read from file %s\n", from);
		exit(98);
	}
}

/**
 * create_file - creates a file.
 * @filename: string pointer to file
 * @text_content: string to write to file
 *
 * Return: 1 on success,
 * -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, count, i, mode = 00664;

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd < 0)
		return (-1);
	for (i = 0; text_content && text_content[i]; i++)
		;
	count = write(fd, text_content, i);
	if (close(fd) < 0)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(100);
	}

	return (count < 0 ? -1 : 1);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size in bytes of the allocated space for `ptr`
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer to the newly allocated memory,
 * or `NULL`
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	size_t i, min = old_size;
	char *new_ptr;

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (0);
	}
	if (new_size == old_size)
		return (ptr);
	if (!ptr)
		return (malloc(sizeof(ptr) * new_size));
	if (new_size < old_size)
	{
		min = new_size;
	}
	new_ptr = malloc(sizeof(ptr) * new_size);

	if (!new_ptr)
		return (0);

	for (i = 0; i < min; i++)
		new_ptr[i] = ((char *)ptr)[i];

	free(ptr);

	return (new_ptr);
}

