#include "main.h"

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
	int fd, count, i, mode = 0;

	if (!*filename)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		mode = 00600;
		close(fd);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd < 0)
		return (-1);
	for (i = 0; text_content && text_content[i]; i++)
		;
	count = write(fd, text_content, i);
	close(fd);

	return (count < 0 ? -1 : 1);
}

