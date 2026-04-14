#include "main.h"

int print_num_recursive(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_num_recursive(n / 10);

	_putchar((n % 10) + '0');
	count++;

	return (count);
}

int print_number(va_list args)
{
	int n;
	unsigned int num;
	int count = 0;

	n = va_arg(args, int);

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	count += print_num_recursive(num);

	return (count);
}
