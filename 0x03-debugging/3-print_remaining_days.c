#include "main.h"

/**
 * print_remaining_days - takes a date and prints how many days are
 * left in the year, taking leap years into account
 * @month: month in number format
 * @day: day of month
 * @year: year
 *
 * Return: void
 */

void print_remaining_days(int month, int day, int year)
{

	if (year % 4 != 0)
		print_simple(month, day, year);

	else if (year % 100 != 0)
		print_leap(month, day);

	else if (year % 400 != 0)
		print_simple(month, day, year);

	else
		print_leap(month, day);
}

/**
  * print_simple - print simple year
  * @m: month
  * @d: day
  * @y: year
  */

void print_simple(int m, int d, int y)
{
	if (m == 2 && d == 60)
	{
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 31, y);
	}
	else
	{
		printf("Day of the year: %d\n", d);
		printf("Remaining days: %d\n", 365 - d);
	}
}

/**
  * print_leap - print simple year
  * @m: month
  * @d: day
  */

void print_leap(int m, int d)
{
	if (m == 2 && d > 60)
		d++;

	printf("Day of the year: %d\n", d);
	printf("Remaining days: %d\n", 366 - d);

}
