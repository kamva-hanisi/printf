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
 * @args: variable va_list
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

/**
 * print_int - Print numbers
 * @args: variable va_list
 * Return: k (nbytes) or (NULL)
 */
int print_int(va_list *args)
{
	long int number;
	int counter, aux_variable, base;

	counter = 0;
	number = va_arg(*args, int);

	if (number < 0)
	{
		number *= -1;
		_putchar(45);
		counter++;
	}
	else if (number >= 0 && number <= 9)
	{
		_putchar(number + 48);
		counter++;
	}
	else if (number > 9)
	{
		base = 10;

		while (number / base > 9)
		{
			base *= 10;
		}

		while (base > 0)
		{
			aux_variable = number / base;
			number = number % base;
			_putchar(aux_variable + 48);
			base = base / 10;
			counter++;
		}
	}

	return (counter);
}

