#include "main.h"

/**
 * _putchar - Entry function. Write characters
 * @c: variable va_list
 *
 * Return: written character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Print character
 * @args: variable va_list
 *
 * Return: 1 (nbyte)
 */
int print_char(va_list *args)
{
	_putchar(va_arg(*args, int));
	return (1);
}

/**
 * print_string - Print string
 * @args: variable char
 * Return: k (nbytes) or (NULL)
 */
int print_string(va_list *args)
{
	const char *str = va_arg(*args, const char *);
	int count = 0;
	int i;

	if (str == NULL)
	{
		write(1, "(null)", 6);

		count = 6;
	}
	else
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);

			count++;
		}
	}

	return (count);
}

