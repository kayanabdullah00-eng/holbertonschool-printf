#include "main.h"

int print_string(va_list args)
{
	char *str;
	int i = 0;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

	return (i);
}
