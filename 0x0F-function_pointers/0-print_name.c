#include "function_pointers.h"

/**
 * print_name - write your short description
 * @name: string pointer
 * @f: pointer to a func, that takes string pointer
 *
 */
void print_name(char *name, void (*f)(char *))
{
	if(name)
		f(name);
}
