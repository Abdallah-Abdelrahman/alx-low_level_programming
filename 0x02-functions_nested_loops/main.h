int _putchar(char c);
void print_alphabet(void);
void print_alphabet_x10(void);
int _islower(int c);
int _isalpha(int c);
int print_sign(int n);
int _abs(int);
int print_last_digit(int);
void jack_bauer(void);
void times_table(void);
int add(int, int);
void print_to_98(int n);
void print_precision(int);
void print_times_table(int n);
void print_table(int);
void print_2p(int);

/**
  * print_precision - print interger based on precision
  * @n: number to print.
  */
void print_precision(int n)
{
	int f, s, t;

	if (n > 99)
	{
		f = n % 10;
		s = (n / 10) % 10;
		t = (n / 10) / 10;
		_putchar(t + '0');
		_putchar(s + '0');
		_putchar(f + '0');

	}

	if (n < 100 && n > 9)
	{

		f = n % 10;
		s = n / 10;
		_putchar(s + '0');
		_putchar(f + '0');

	}

	if (n < 10)
	{
		_putchar(n + '0');
	}
}
