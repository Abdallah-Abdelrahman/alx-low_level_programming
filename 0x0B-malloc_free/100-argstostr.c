#include "main.h"

/**
 * argstostr - concatenates all the arguments of your program.
 * @ac: number of arguments
 * @av: array of pointers to string
 *
 * Return: pointer to the new string,
 * NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
	int i = 0, k = 0, j;
	char *ptr;

	if (ac < 2)
		return (0);
	if (!*av)
		return (0);

	ptr = malloc((sizeof(*av) * ac) + ac + 1);
	if (!ptr)
		return (0);
	for (; av[i]; i++)
	{
		for (j = 0; av[i][j]; j++, k++)
			ptr[k] = av[i][j];
		ptr[k] = '\n';
	}
	ptr[i] = '\0';

	return (ptr);

}
