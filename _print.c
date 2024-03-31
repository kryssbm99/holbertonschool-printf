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
    va_list args; /* Variable argument list */
    int count = 0; /* Counter for characters printed */

    va_start(args, format); /* Initialize va_list to access variable arguments */
	
    while (*format)  /* Loop through the format string */
    {
        if (*format != '%') /* If current character is not a format specifier */
        {
            _putchar(*format); /* Print the character */
            count++; /* Increment the character count */
        }
        else /* If current character is a format specifier */
        {
            format++; /* Move to the next character to check the specifier */

	    /* Determine the type of format specifier */
            switch (*format)
            {
            case 'c': /* Character specifier */
                count += printchar(args); /* Print char */
                break;
            case 's': /* String specifier */
                count += printstring(args); /* Print string */
                break;
            case '%': /* Percent specifier */
                count += printpercent(args); /* Print percent */
                break;
	    case 'i': /* Integer specifier */
	    case 'd': /* Integer specifier */
		count += printint(args); /* Print integer */
		break;
	 default: /* Unknown specifier */
		 _putchar('%'); /* Print percent character */
		_putchar(*format); /* Print unknown character */
		count += 2; /* Increment character count by 2 */
		break;
            }
        }
        format++; /* Move to the next character in the format string */
    }
	va_end(args); /* Clean up the va_list */
	
    return (count); /* Return the total count of characters printed */
}
