#include <stdio.h>

/**
* main - write your descirption here
*
* Return: 0 as exit status
*/
int main(void)
{
	int i = 0, j = i + 1,
	    comma = 44, space = 32, nums[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};

	while (i < 99)
	{
		while (j < 100)
		{
			putchar(nums[i / 10]);
			putchar(nums[i % 10]);
			putchar(space);
			putchar(nums[j / 10]);
			putchar(nums[j % 10]);
			if (i != 98)
			{
				putchar(comma);
				putchar(space);
			}
			j++;
		}
		/* book keeping 0_o */
		i++;
		j = i + 1;
	}
	putchar(10);

	return (0);
}
