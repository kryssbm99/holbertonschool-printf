#include "main.h"

/**
 * printstring - Function prints a strings
 * @val: Val Variable
 * Return: Number of characters printed
 */
int printstring(va_list val)
{
    int i = 0; /* Iterator of string */
    char *s; /* Pointer to string */
    int count = 0; /* Count of characters printed

    /* Retrieve the string argument from va_list */
    s = va_arg(val, char*);

    if (s == NULL)
    {
        s = "(null)"; /* Prints (null) */
    }

    /* Prints each character in string */
    while (s[i] != '\0')
    {
        _putchar(s[i]);
        count++;
        i++;
    }
    return (count);
}

/**
 * printchar - Function prints characters
 * @val: Val Variable
 * Return: Number of characters printed
 */
int printchar(va_list val)
{
     return (_putchar(va_arg(val, int))); /* Prints a character argument retrieved from va_list */
}

/**
 * printint - Function prints integers
 * @val: Parameter Variable
 * Description:
 * This function prints an integer argument retrieved from a va_list.
 *   It handles both positive and negative integers
 * Return: Number of characters printed
 */
int printint(va_list val)
{
    int n = va_arg(val, int); /* Retrieve int argument */
    int count = 0; /* Count of characters printed */
    int divisor = 1; /* Divisor for extracting digits */
    int temp; /* Temporary variable for calculations */
    int zero = 0;

    if (n == zero)
    {
        _putchar('0');
        return 1;
    }

    /* If the integer is negative, print '-' and make it positive */
    if (n < zero)
    {
        _putchar('-');
        count++;
        n = -n;
    }

    temp = n;
    /* Find the divisor for the most significant digit */
    while (temp / 10 != zero)
    {
        divisor *= 10;
        temp /= 10;
    }

    while (divisor != zero) 
    {
        int digit = n / divisor; /* Extract the most significant digit */
        _putchar(digit + '0'); /* Convert digit
        count++; /* Increment count of characters printed */
        n %= divisor; /* Remove the most significant digit */
        divisor /= 10; /* Update divisor for the next digit */
    }

    return count; /* Return the total characters printed */
}
/**
 * printpercent - Function prints the '%' character
 * @val: Parameter Variable
 * Return: Number of characters printed
 */
int printpercent(va_list val)
{
    (void)val;    /* Ignoring the va_list argument */
    _putchar('%'); /* Print % character */
    return (1); /* Return 1 (only one character printed)
}
