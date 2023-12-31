#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * printInteger - prints the integer specifier
 * @num: integer input
 */

void printInteger(int num)
{
	int tempCount = 0, numCopy = num, i, divisor = 1;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	do {
		tempCount++;
		numCopy /= 10;
	} while (numCopy != 0);

	for (i = 1; i < tempCount; i++)
	{
		divisor *= 10;
	}

	do {
		int digit = num / divisor;

		_putchar(digit + '0');
		num %= divisor;
		divisor /= 10;
	} while (divisor != 0);
}

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */


int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int ch = va_arg(args, int);

				_putchar(ch);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);

				while (*str != '\0')
				{
					_putchar(*str);
					str++;
					count++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				printInteger(num);
				count++;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
