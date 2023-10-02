#include "main.h"
#include <unistd.h>

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: string pointer
 * @text_content: string pointer
 * Return: 1 on success,
 * -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int i, fd, count, mode = 00600;
	(void)mode;

	if (!*filename)
		return (-1);
	fd = open(filename, O_APPEND | O_WRONLY);
	if (fd < 0)
		return (-1);
	if (!text_content)
		return (1);
	for (i = 0; text_content[i]; i++)
		;
	count = write(fd, text_content, i);
	close(fd);

	return (count < 0 ? -1 : 1);
}
