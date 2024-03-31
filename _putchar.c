#include <unistd.h>

/**
 *_putchar - Function writes the character to stdout
 *
 *
 *@c: Char to print
 *
 *Return: 1
 */
int _putchar(char c)
{
	return(write(1, &c, 1));
}
