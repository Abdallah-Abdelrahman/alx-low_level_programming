#include "main.h"

/**
 * change - prints the minimum number of coins to make change
 * @argc: number of arguments
 * @argv: array of pointers
 *
 * Return: 1 if the arguments passed not equal 2, 0 otherwise
 */
int main(int argc, char *argv[])
{
	int len = 0, sum = 0, count = 0, amount;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	for (; argv[1][len]; len++)
		;

	amount = stoi(argv[1], len);

	if (amount < 0)
		printf("%d\n", 0);
	else
	{
		while (sum != amount)
		{
			sum += next_change(4, amount - sum);
			count++;
		}
		printf("%d\n", count);

	}
	return (0);
}

/**
 * count_changes - count the minimum numbers of coins to make a change
 * @amount: amount of money
 * @sum: sum of changes
 *
 * Return: count of changes 
 */
int count_changes(int amount, int sum)
{
	if (sum == amount)
		return (0);
	return (1 + (count_changes(amount, next_change(4, amount - sum))));
}

/**
 * next_change - find the next change for the amount of money
 * @idx: position of the largest change
 * @amount: amount of money
 *
 * Return: change
 */
int next_change(int idx, int amount)
{
	int changes[] = {1, 2, 5, 10, 25};

	if (changes[idx] <= amount)
		return (changes[idx]);
	return (next_change(idx - 1, amount));
}

/**
 * stoi - convert string to integer
 * @ptr: string pointer
 * @size: size of the string
 *
 * Return: integer representation of the string, if negative return `0`
 */
int stoi(char *ptr, int size)
{
	int i = 0, num = 0, negative = 1;

	for (; ptr[i]; i++)
	{
		if (ptr[i] == '-')
		{
			negative *= -1;
			continue;
		}
		if (i != size - 1)
			num += (ptr[i] - 48) * _pow_recursion(10, size - (i + 1));
		else
			num += (ptr[i] - 48);

	}

	return (num * negative);
}

/**
 * _pow_recursion - calculate the power of x^y
 * @x: the base
 * @y: the power
 *
 * Return: x^y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
