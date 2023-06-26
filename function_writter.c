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
 * print_string - Print string
 * @str: variable char
 * Return: k (nbytes) or (NULL)
 */
int print_string(char *str)
{
	int count = 0;
        int i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		count++;
	}

	return (count);
}

