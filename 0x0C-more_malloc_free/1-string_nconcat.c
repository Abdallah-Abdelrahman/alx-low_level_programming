#include "main.h"

/**
 * string_nconcat - concatenates two strings.
 * @s1: 1st string
 * @s2: 2nd string
 * @n: number of bytes to copy from @s2
 *
 * Return: a pointer to a newly allocated space in memory
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int i = 0, len1 = 0, len2 = 0, size = 0;
	char *ptr;

	for (; (s1 && s1[len1]) || (s2 && s2[len2]); )
	{
		if (s1 && s1[len1])
			len1++;
		if (s2 && s2[len2])
			len2++;
	}

	size = len1 + (n >= len2 ? len2 : n);
	ptr = malloc(sizeof(*ptr) * size + 1);

	if (!ptr)
		return (0);

	for (len1 = 0, len2 = 0; i < size; i++)
		ptr[i] = s1 && s1[len1]
			? s1[len1++]
			: s2 && s2[len2]
			? s2[len2++] : '\0';

	return (ptr);
}
