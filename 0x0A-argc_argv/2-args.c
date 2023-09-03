#include "main.h"

/**
 * main - prints all the arguments it recieves
 * @argc: number of args
 * @argv: array of pointers to string
 *
 * Return: 0 as exit status
 */
int main(int argc, char **argv)
{
	while (argc--)
		printf("%s\n", *argv++);
	return (0);
}
