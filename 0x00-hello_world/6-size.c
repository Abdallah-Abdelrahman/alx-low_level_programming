#include <stdio.h>

/**
 * main - print the size of various sizes on computer it's compiled on
 * Return: 0 as success value exit status
 */
int main(void)
{
	printf("Size of a char: %d byte(s)", sizeof(char));
	printf("\nSize of an int: %d byte(s)", sizeof(int));
	printf("\nSize of a long: %d byte(s)", sizeof(long));
	printf("\nSize of a long long int: %d byte(s)", sizeof(long long int));
	printf("\nSize of a float: %d byte(s)", sizeof(float));
	return (0);
}
