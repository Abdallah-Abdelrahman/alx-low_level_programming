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
	return (strstr(haystack, needle));

}
