#include "main.h"

/**
 * my_atoi - for exit status extract numbers
 * from string i.e. ascii
 * and convert the numbers to integer
 * @strn: input string from exit(strn)
 * Return: number as integer
 */
int my_atoi(char *strn)
{char *s = strn;
	int y, k, xtrctd_num, sign;

	y = 0;
	xtrctd_num = 0;
	sign = 1;
	/* Skip any leading non-numeric chars except (-)*/
	while ((*(s + y) < '0' || *(s + y) > '9') && (*(s + y) != '\0'))
	{
		if (*(s + y) == '-')/*not needed 4 this proj. but general*/
		{
			sign *= -1;
		}
		y++;
	}
	/* Convert numeric characters to int */
	k = y;
	while ((*(s + k) >= '0') && (*(s + k) <= '9'))
	{
		xtrctd_num = xtrctd_num * 10 + sign * (*(s + k) - '0');
		/*
		 *1st: xtrctd_num * 10 shifts
		 *old numbers to left to add new
		 *
		 * 2nd: *(s + k) get char at j-th position of input str
		 *
		 * (*(s + k) - '0') converts num
		 * from char to int value via subtracting ascii codes
		 */
		k++;
	}
	return (xtrctd_num);
}
