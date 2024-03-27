#ifndef MAIN_H_
#define MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

void _printf(const char * const format, ...);
int _putchar(char c);
void printchar(va_list var);
void printstring(va_list var);
void printint(va_list var);
void printpercent(va_list var);

/**
 *struct type - Struct function
 *@t: Char variable for t
 *@f: Pointer of f
 *
 */
typedef struct type
{
	char t;
	void(*f)(va_list);
} type;
#endif
