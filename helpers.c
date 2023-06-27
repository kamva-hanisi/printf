#include "main.h"

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

