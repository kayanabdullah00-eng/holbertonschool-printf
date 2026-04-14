
#include "main.h"

int print_num_recursive(int n)
{
	int count = 0;
	unsigned int num;

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

	if (num / 10)
		count += print_num_recursive(num / 10);

	_putchar((num % 10) + '0');
	count++;

	return (count);
}

int print_number(va_list args)
{
	int n;

	n = va_arg(args, int);
	return (print_num_recursive(n));
}
