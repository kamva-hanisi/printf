#include "main.h"

/**
 * _printf - custom printf function
 * @format: va_args
 * Return: characters_number
 */
int _printf(const char *format, ...)
{
	int i = 0, characters_number = 0;

	va_list args;

	va_start(args, format);

	if (!format)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '\0')
				return (-1);

			characters_number += func_caller(format[i], &args);
		}
		else
		{
			_putchar(format[i]);
			characters_number++;
		}
	}

	va_end(args);

	return (characters_number);
}

