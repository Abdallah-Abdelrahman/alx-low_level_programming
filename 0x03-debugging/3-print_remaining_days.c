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
		print_leap(month, day, year);

	else if (year % 400 != 0)
		print_simple(month, day, year);

	else
		print_leap(month, day, year);
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

void print_leap(int m, int d, int y)
{
	if (m == 2 && d > 60)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 31, y);
	if (m == 3 && d > 91)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 60, y);
	if (m == 4 && d > 121)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 91, y);
	if (m == 5 && d > 152)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 121, y);
	if (m == 6 && d > 182)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 152, y);
	if (m == 7 && d > 213)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 182, y);
	if (m == 8 && d > 244)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 213, y);
	if (m == 9 && d > 274)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 244, y);
	if (m == 10 && d > 305)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 274, y);
	if (m == 11 && d > 335)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 305, y);
	if (m == 12 && d > 366)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 335, y);

	else
	{
		printf("Day of the year: %d\n", d);
		printf("Remaining days: %d\n", 366 - d);
	}

}
