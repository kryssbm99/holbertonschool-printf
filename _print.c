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
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
	
    while (*format)
    {
        if (*format != '%')
        {
            _putchar(*format);
            count++;
        }
        else
        {
            format++; 
	    
            switch (*format)
            {
            case 'c':
                count += printchar(args);
                break;
            case 's':
                count += printstring(args);
                break;
            case '%':
                count += printpercent(args);
                break;
	    case 'i':
	    case 'd':
		count += printint(args);
		break;
            default:
	        _putchar('%');
		_putchar(*format);
		count += 2;
		break;
            }
        }
        format++;
    }
    va_end(args);
    return (count);
}
