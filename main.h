#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list *args);
int _putchar(char c);
int print_string(va_list *args);
int print_int(va_list *args);
int print_binary(va_list *args);
int print_big_numbers(long int number);

/**
 * struct types - structure for print_func
 * @formatter: pointer to character
 * @function_writer: function pointer to function writers
 */
typedef struct types
{
	char formatter;
	int (*function_writer)(va_list *args);
} print_func;

int func_caller(const char formatter, va_list *args);

#endif /* MAIN_H */

