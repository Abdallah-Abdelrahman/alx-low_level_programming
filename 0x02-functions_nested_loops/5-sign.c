
/**
* print_sign - prints the sign of a number
* @n: intger param
*
* Return: 1 if n > 0,
* -1 if n < 0,
* 0 if n == 0
*/
int print_sign(int n)
{
	int result;

	if (n > 0)
	{
		result = 1;
		_putchar('+');
	}

	else if (n < 0)
	{
		result = -1;
		_putchar('-');
	}

	else
	{
		result = 0;
		_putchar('0');
	}

	return (result);
}
