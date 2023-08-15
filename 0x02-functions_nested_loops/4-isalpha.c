#include <stdio.h>

/**
* _isalpha - checks for alphabetic character
* @c: Single character
*
* Return: 1 if c is a letter (lower or upper)
*/
int _isalpha(int c)
{
	return (isalpha(c) ? 1 : 0);
}
