#include <stdio.h>

/**
 * rand - write your short description
 *
 * Return: elem from array
 */
int rand(void)
{

	static int i;
	int arr[] = {8, 8, 7, 9, 23, 74};

	i = i < 6 ? i : 0;

	return (arr[i++]);

}

