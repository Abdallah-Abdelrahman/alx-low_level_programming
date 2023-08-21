#include "main.h"

/**
 * rev_string - reverse a string
 * @s: pointer to string to be reversed
 *
 */
void rev_string(char *s)
{
	int len = 0, i = 1;

	while (*s)
	{
		s++;
		len++;
	}
	while (i < len)
	{
		/* swap */
		char tmp = *(s - i);
		*(s - i) = *(s - len);
		*(s - len) = tmp;

		/* book keeping o_0 */
		len--;
		i++;
	}

}
