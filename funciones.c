#include "main.h"

/**
 * printstring - Function prints a strings
 * @val: Val Variable
 * Return: Number of characters printed
 */
int printstring(va_list val)
{
    int i = 0;
    char *s;
    int count = 0;

    s = va_arg(val, char*);

    if (s == NULL)
    {
        s = "(null)";
    }
    while (s[i] != '\0')
    {
        _putchar(s[i]);
        count++;
        i++;
    }
    if (s == NULL)
    {
	    count += 6;
    }
    return count;
}

/**
 * printchar - Function prints characters
 * @val: Val Variable
 * Return: Number of characters printed
 */
int printchar(va_list val)
{
     return (_putchar(va_arg(val, int)));
}

/**
 * printint - Function prints integers
 * @val: Parameter Variable
 * Return: Number of characters printed
 */
int printint(va_list val)
{
    int n = va_arg(val, int);
    int count = 0;
    int divisor = 1;
    int temp;

    if (n == 0)
    {
        _putchar('0');
        return 1;
    }

    if (n < 0)
    {
        _putchar('-');
        count++;
        n = -n;
    }

    temp = n;
    while (temp / 10 != 0)
    {
        divisor *= 10;
        temp /= 10;
    }

    while (divisor != 0)
    {
        int digit = n / divisor;
        _putchar(digit + '0');
        count++;
        n %= divisor;
        divisor /= 10;
    }

    return (count);
}
/**
 * printpercent - Function prints the '%' character
 * @val: Parameter Variable
 * Return: Number of characters printed
 */
int printpercent(va_list val)
{
    (void)val;
    _putchar('%');
    return (1); 
}

