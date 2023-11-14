#include <stdio.h>

/**
 * inject - write your short description
 *
 * Return: elem from array
 */
int inject(void)
{
/* 	printf("Congratulations, you win the Jackpot!"); */

/**
 * 	static int i;
 * 	int arr[] = {8, 8, 7, 9, 23, 74};
 * 
 * 	i = i < 6 ? i : 0;
 * 
 * 	return (arr[i++]);
 */
	static int ct = -1;

	ct++;
	if (ct == 0)
		return 8;
	if (ct == 1)
		return 8;
	if (ct == 2)
		return 7;
	if (ct == 3)
		return 9;
	if (ct == 4)
		return 23;
	if (ct == 5)
		return 74;
	return (ct * ct % 30000);
}

