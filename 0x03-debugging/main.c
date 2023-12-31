#include <stdio.h>
#include "main.h"

/**
* main - write your short description
* Description: Long desc
*
* Return: 0 as exit status
*/
int main(void)
{
	/*February 29, 1991*/
	int month;
	int day;
	int year;
	
	month = 04;
	day = 31;
	year = 1991;
	
	/**
	 *printf("Date: %02d/%02d/%04d\n", 02, 29, 2000);
	 *print_remaining_days(month, convert_day(02, 29), 2000);


	 *printf("Date: %02d/%02d/%04d\n", 02, 29, 2427);
	 *print_remaining_days(month, convert_day(02, 29), 2427);
	 */

	printf("Date: %02d/%02d/%04d\n", month, day, year);
	print_remaining_days(month, convert_day(month, day), year);
	return (0);
}

/**
* convert_day - converts day of month to day of year, without accounting
* for leap year
* @month: month in number format
* @day: day of month
* Return: day of year
*/

int convert_day(int month, int day)
{
    switch (month)
    {
        case 2:
            day = 31 + day;
            break;
        case 3:
            day = 59 + day;
            break;
        case 4:
            day = 90 + day;
            break;
        case 5:
            day = 120 + day;
            break;
        case 6:
            day = 151 + day;
            break;
        case 7:
            day = 181 + day;
            break;
        case 8:
            day = 212 + day;
            break;
        case 9:
            day = 243 + day;
            break;
        case 10:
            day = 273 + day;
            break;
        case 11:
            day = 304 + day;
            break;
        case 12:
            day = 334 + day;
            break;
        default:
            break;
    }
    return (day);
}
