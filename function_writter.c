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
	char *str = va_arg(*args, char *);
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
 * print_big_numbers - Print whole numbers
 * @number: variable long int
 * Return: k (nbytes)
 */
int print_big_numbers(long int number)
{
	int base_value = 10, count = 0, aux;

	if (number >= 0 && number <= 9)
	{
		_putchar(number + 48);
		count++;
	}
	else
	{
		while (number / base_value > 9)
		{
			base_value *= 10;
		}

		while (base_value > 0)
		{
			aux = number / base_value;
			number = number % base_value;
			_putchar(aux + 48);
			base_value = base_value / 10;
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
	int count = 0;
	long int number = va_arg(*args, int);

	if (number < 0)
	{
		number *= -1;
		_putchar(45);
		count++;

		count += print_big_numbers(number);
	}
	else if (number >= 0 && number <= 9)
	{
		_putchar(number + 48);
		count++;
	}
	else if (number > 9)
	{
		count += print_big_numbers(number);
	}

	return (count);
}

