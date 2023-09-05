#include "main.h"

/**
 * strtow - splits a string into words.
 * @str: string pointer
 *
 * Return: a pointer to an array of string, or `NULL`
 */
char **strtow(char *str)
{
	int i, l, m, wlen, j = 0, len = 0, count = 0, size = 0;
	char **ptr;

	if (!str)
		return (0);
	for (; str[len]; len++)
	{
		if (str[i] != 32)
			size++;
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
	for (i = 0; i < len; i++)
	{
		if ((i == 0 && str[i] != 32) ||
				(str[i] != 32 && str[i - 1] == 32))
		{
			wlen = word_len(str, i);
			m = i;
			ptr[j] = malloc((sizeof(**ptr) * wlen) + 1);
			if (ptr[j])
			{
				for (l = 0; l < wlen; l++, m++)
					ptr[j][l] = str[m];
				ptr[j][l] = '\0';

			}
			j++;
		}
	}
	ptr[j] = NULL;
	return (ptr);
}

/**
 * split - split string into array of words
 * @src: array of pointers to string
 * @t: string pointer
 * @len: size of target
 */
void split(char **src, char *t, int len)
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
			j++;
		}
	}
	src[j] = NULL;
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
