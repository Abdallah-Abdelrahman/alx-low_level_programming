#include "main.h"

/**
 * is_palindrome - check if a string palindrome
 * @s: string
 *
 * Return: 1 if it's, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	return (comparer(s, 0, len - 1));
}

/**
 * comparer - compare first with last character
 * @s: string pointer
 * @f: 1st character
 * @l: last char
 * Return: 1 f == l, 0 otherwise
 */
int comparer(char *s, int f, int l)
{
	if (f >= l)
		return (1);
	if (s[f] != s[l])
		return (0);
	return (comparer(s, f + 1, l - 1));
}


/**
 * _strlen_recursion - returns the length of a string.
 * @s: string pointer
 *
 * Return: the length of the string
 */
int _strlen_recursion(char *s)
{
	if (!*s)
		return (0);
	return (1 + _strlen_recursion(s + 1));
}
