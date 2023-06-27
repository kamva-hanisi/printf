#include "main.h"

/**
 * func_caller - function for calling other functions
 * @formatter: char
 * @args: va_list
 * Return: character count
 */
int func_caller(char formatter, va_list *args)
{

	print_func print_options[] = {
		{'c', print_char},
		{'s', print_string},
		{'\0', NULL}};

	int print_options_size = sizeof(print_options) / sizeof(print_options[0]);

	int i;
	int count = 0;
	int characters_number = 0;

	for (i = 0; i < print_options_size; i++)
	{
		if (print_options[i].formatter == formatter)
		{
			characters_number += print_options[i].function_writer(args);
			count++;
		}
	}

	if (count == 0)
	{
		_putchar('%');
		_putchar(formatter);
		characters_number++;
	}

	return (characters_number);
}

