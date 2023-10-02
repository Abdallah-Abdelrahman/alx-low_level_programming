#include "main.h"

/**
 * read_textfile - reads a text file.
 * Description: and prints it to the POSIX standard output.
 * @filename: file name
 * @letters: number of letters
 *
 * Return: the actual number of letters it could read and print,
 * 0 if file cann't be open or read.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	size_t count, bytes;
	char *buf = 0;

	if (!*filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = malloc(sizeof(*buf) * letters);
	if (!buf)
		return (0);
	bytes = read(fd, buf, letters);
	if (bytes < 0)
		return (0);

	count = write(STDOUT_FILENO, buf, letters);

	return (count != letters ? 0 : count);
}
