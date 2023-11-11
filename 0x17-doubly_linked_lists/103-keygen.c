#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


/**
 * encode1 - encode1
 * @arg1: arg1
 * @arg2: arg1
 * Return: integer
 */
uint64_t encode1(char *arg1, int arg2)
{
	int var_10 = 0, i;

	for (i = 0; i < arg2; i = (i + 1))
	{
		var_10 = (var_10 + *(arg1 + i));
	}
	return ((var_10 ^ 0x4f) & 0x3f);
}

/**
 * encode2 - encode2
 * @arg1: arg1
 * @arg2: arg1
 * Return: integer
 */
uint64_t encode2(char *arg1, int arg2)
{
	int var_10 = 1, i;

	for (i = 0; i < arg2; i = (i + 1))
	{
		var_10 = (*(arg1 + i) * var_10);
	}
	return ((var_10 ^ 0x55) & 0x3f);
}

/**
 * encode3 - encode3
 * @arg1: arg1
 * @arg2: arg1
 * Return: integer
 */
uint64_t encode3(char *arg1, int arg2)
{
	int var_10 = *arg1, i;

	for (i = 0; i < arg2; i = (i + 1))
	{
		if (arg1[i] > var_10)
		{
			var_10 = arg1[i];
		}
	}
	srand((var_10 ^ 0xe));
	return (rand() & 0x3f);
}

/**
 * encode4 - encode4
 * @arg1: arg1
 * @arg2: arg1
 * Return: integer
 */
uint64_t encode4(char *arg1, int arg2)
{
	int var_10 = 0, i, rax_12;

	for (i = 0; i < arg2; i = (i + 1))
	{
		var_10 = (var_10 + (*(arg1 + i) * *(arg1 + i)));
	}
	rax_12 = (var_10 ^ 0xef);
	return (rax_12 & 0x3f);
}


/**
 * main - main
 * @argc: argc
 * @argv: argv
 * Return: 0
 */
int main(__attribute__((unused))int argc, char **argv)
{
	char *var_58 =
		"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	int len = strlen(argv[1]), var_10 = 0, i, rax_3,
	    rax_10 = (len ^ 0x3b) & 0x3f,
	    rax_16 = encode1(argv[1], len),
	    rax_23 = encode2(argv[1], len),
	    rax_30 = encode3(argv[1], len),
	    rax_37 = encode4(argv[1], len),
	    rax_46;


	for (i = 0; *argv[1] > i; i = (i + 1))
	{
		var_10 = rand();
	}
	rax_3 = (var_10 ^ 0xe5);
	rax_46 = (rax_3 & 0x3f);

	printf("%c", var_58[rax_10]);
	printf("%c", var_58[rax_16]);
	printf("%c", var_58[rax_23]);
	printf("%c", var_58[rax_30]);
	printf("%c", var_58[rax_37]);
	printf("%c\n", var_58[rax_46]);


	return (0);
}

