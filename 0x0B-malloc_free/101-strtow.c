#include "main.h"

/**
 * strtow - splits a string into words.
 * @str: string pointer
 *
 * Return: a pointer to an array of string, or `NULL`
 */
char **strtow(char *str)
{
	int len = 0, count = 0;
	char **ptr;

	if (!str)
		return (0);
	for (; str[len]; len++)
	{
		if (str[len] == 32)
			continue;
		if (str[len + 1] == 32)
			count++;
	}
	if (!len)
		return (0);
	if (str[len - 1] != 32)
		count++;
	ptr = malloc((sizeof(*ptr) * count) + count + 1);
	if (!ptr)
		return (0);
	if (count == 0)
		return (0);
	return (split(ptr, str, len));
}

/**
 * split - split string into array of words
 * @src: array of pointers to string
 * @target: string pointer
 * @len: size of target
 *
 * Return: array of pointers to string,
 * NULL on failure
 */
char **split(char **src, char *target, int len)
{
	int i, l, wlen, m, j = 0;

	for (i = 0; i < len; i++)
	{
		if ((i == 0 && target[i] != 32) ||
				(target[i] != 32 && target[i - 1] == 32))
		{
			wlen = word_len(target, i);
			m = i;
			src[j] = malloc((sizeof(**src) * wlen) + 1);
			if (src[j])
			{
				for (l = 0; l < wlen; l++, m++)
					src[j][l] = target[m];
				src[j][l] = '\0';
			}
			else
				return (0);
			j++;
		}
	}
	src[j] = NULL;
	return (src);
}

/**
 * word_len - get the length of a word in a string
 * @ptr: string pointer
 * @idx: position to start looking for a word
 *
 * Return: length of the word
 */
int word_len(char *ptr, int idx)
{
	if (ptr[idx] != 32 && (ptr[idx + 1] == 32 || ptr[idx + 1] == '\0'))
		return (1);
	return (1 + word_len(ptr, idx + 1));
}
