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

/**
 * print_binary - converting to a binary value
 * @args: decimal number
 * Return: k (nbytes)
 */
int print_binary(va_list *args)
{
	int binary_number = va_arg(*args, int);
	unsigned int number = (unsigned int)binary_number;
	unsigned int pow_of_two = 1;
	int counter = 0;

	if (binary_number == 0)
	{
		_putchar('0');
		counter++;

		return (counter);
	}

	while (pow_of_two <= number / 2)
	{
		pow_of_two *= 2;
	}

	while (pow_of_two > 0)
	{
		int digit_number = 0;

		if (number & pow_of_two)
		{
			digit_number = 1;
		}

		_putchar(digit_number + '0');
		counter++;
		pow_of_two /= 2;
	}

	return (counter);
}

