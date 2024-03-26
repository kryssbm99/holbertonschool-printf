#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing directives
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list par;
	int i, j;
	int count = 0;

	type style[] = 
	{
		{'c', printchar},
		{'s', printstring},
		{'%', printpercent},
		{'i', printint}
	};

	va_start(par, format);
		
	i = 0;
	while (format && format[i])
	{
		j = 0;
			while (style[j].t)
		{
			if (style[j].t == format[i])
			{
				style[j].f(par);
				count++;
			}
			j++;
		}
	i++;
	}

	va_end(par);
	return (count);
}
