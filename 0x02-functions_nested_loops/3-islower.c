#include <ctype.h>

/**
* _islower - checks for lowercase.
* @c: single charcter
*
* Return: 1 if c is lower,
* 0 otherwise.
*/
int _islower(int c)
{
	return (islower(c) > 0 ? 1 : 0);

}
