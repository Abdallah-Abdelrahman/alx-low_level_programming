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
	if (m == 2 && d > 59)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 31, y);
	else if (m == 3 && d > 90)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 59, y);
	else if (m == 4 && d > 120)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 90, y);
	else if (m == 5 && d > 151)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 120, y);
	else if (m == 6 && d > 181)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 151, y);
	else if (m == 7 && d > 212)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 181, y);
	else if (m == 8 && d > 243)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 212, y);
	else if (m == 9 && d > 273)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 243, y);
	else if (m == 10 && d > 304)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 273, y);
	else if (m == 11 && d > 334)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 304, y);
	else if (m == 12 && d > 365)
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 334, y);

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
  * @y: year
  */

void print_leap(int m, int d, int y)
{
	if (m == 2 && (d > 60 || d < 32))
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 31, y);
	else if (m == 3 && (d > 91 || d < 61))
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 60, y);
	else if (m == 4 && (d > 121 || d < 92))
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 91, y);
	else if (m == 5 && (d > 152 || d < 122))
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 121, y);
	else if (m == 6 && (d > 182 || d < 153))
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 152, y);
	else if (m == 7 && (d > 213 || d < 183))
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 182, y);
	else if (m == 8 && (d > 244 || d < 214))
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 213, y);
	else if (m == 9 && (d > 274 || d < 245))
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 244, y);
	else if (m == 10 && (d > 305 || d < 275))
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 274, y);
	else if (m == 11 && (d > 335 || d < 306))
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 305, y);
	else if (m == 12 && (d > 366 || d < 336))
		printf("Invalid date: %02d/%02d/%04d\n", m, d - 335, y);
	else
	{
		printf("Day of the year: %d\n", d);
		printf("Remaining days: %d\n", 366 - d);
	}
}
