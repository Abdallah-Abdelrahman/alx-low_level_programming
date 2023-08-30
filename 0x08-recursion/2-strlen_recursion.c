#include "main.h"

/**
 * strlen_recursion - returns the length of a string.
 * @s: string pointer
 *
 * Return: the length of the string
 */
int _strlen_recursion(char *s)
{
	if(!*s)
		return (0);	
	return (1 + _strlen_recursion(++s));
}
