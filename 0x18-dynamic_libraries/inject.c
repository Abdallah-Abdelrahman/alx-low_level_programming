#include "main.h"

/**
 * inject - write your short description
 *
 * Return: elem from array
 */
int inject(void)
{
	static int i;
	static int arr[] = {8, 8, 7, 9, 23, 74};

	i = i < 6 ? i : 0;

	return (arr[i++]);
}

