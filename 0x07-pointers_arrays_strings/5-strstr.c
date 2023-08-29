#include "main.h"
#include <string.h>

/**
 * _strstr - locates a substring
 * @haystack: string to search in
 * @needle: string to search for
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0, j = 0, len = strlen(needle);
	char *ptr;

	for (; haystack[i]; i++)
	{
		for (; needle[j]; )
		{
			if (haystack[i] != needle[j])
			{
				j = 0;
				break;
			}
			if (haystack[i] == needle[j])
			{
				if (j == 0)
					ptr = &haystack[i];
				j++;
				break;
			}
		}
	}
	if (j != len)
		return (NULL);
	return (ptr);

}
