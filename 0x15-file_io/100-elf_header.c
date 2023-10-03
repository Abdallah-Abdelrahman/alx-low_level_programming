#include "main.h"

/**
 * main - displays the information contained in the ELF header.
 * @ac: ac
 * @av: av
 *
 * Return: 0 as exit status
 */
int main(int ac, char **av)
{
	int fd, bytes;
	char *elf, buf[BUFFER], *magic = "\x7F\x45\x4c\x46";

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Error: no file supplied\n");
		exit(98);
	}
	elf = av[1];
	fd = open(elf, O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: faied to read %s\n", elf);
		exit(98);
	}
	bytes = read(fd, buf, 4);
	if (bytes < 0)
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: faied to read %s\n", elf);
		exit(98);
	}
	buf[bytes] = 0;
	if (_strcmp(magic, buf) != 0)
	{
		close(fd);
		dprintf(STDERR_FILENO,
		"Error: Not an ELF file - it has the wrong magic %s\n", elf);
		exit(98);
	}
	close(fd);
	printf("It's an ELF\n");

	return (0);
}

/**
 * _strcmp - compares 2 strings
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: 0 if s1 & s2 are equal,
 * a negative value if s1 < s2
 * a positive value if s1 > s2
 *
 */
int _strcmp(char *s1, char *s2)
{
	int ret = 0;

	for (; *s1 && *s2; s1++, s2++)
	{
		if (*s1 != *s2)
		{
			ret = *s1 - *s2;
			break;
		}
	}

	return (ret);
}
