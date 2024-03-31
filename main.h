#ifndef MAIN_H_
#define MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char * const format, ...);
int _putchar(char c);
int printchar(va_list val);
int printstring(va_list val);
int printint(va_list val);
int printpercent(va_list val);

#endif
