#include "3-calc.h"

/**
 * get_op_func - selects the function corresponds to the operation
 * @s: the operation
 *
 * Return: pointer to a function,
 * NULL if no operation matches
 */
int (*get_op_func(char *s))(int, int)
{
	int i;
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	while (i < 6)
	{
		if (ops[i].op && *s == ops[i].op[0])
			return (ops[i].f);

		i++;
	}

	return (NULL);
}
