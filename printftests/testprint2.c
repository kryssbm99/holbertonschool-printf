#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_func - Processes the format string and calls the appropriate print functions
 * @format: Format string containing directives
 * @val: va_list containing variable arguments
 *
 * Return: Number of characters printed (excluding null byte)
 */
int print_func(const char *format, va_list val)
{
        int i, j;
        int count = 0;

        functions type[] =
        {
                {'c', printchar},
                {'s', printstring},
                {'%', printpercent},
                {'i', printint},
		{'d', printint},
                {0, NULL}
        };

        i = 0;

        while (format && format[i])
        {
                if (format[i] != '%')
                {
                        _putchar(format[i]);
                        count++;
                }
                else if (format[i] == '%')
                {
                        i++;
                        j = 0;
                        while (type[j].b)
                        {
                                if (type[j].b == format[i])
                                {
					type[j].p(val);
					break;
                                }
                                j++;
                        }
                }
		i++;
        }
        return (count);
}

/**
 * _printf - Main function of printf
 * @format: Format string
 * @...: Variable arguments
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
        va_list val;
        int count;

        va_start(val, format);

        if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        {
                return (0);
        }
        count = print_func(format, val);

        va_end(val);
        return (count);
}
