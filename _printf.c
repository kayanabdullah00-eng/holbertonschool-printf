#include "main.h"

int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == '%')
				count += write(1, "%", 1);
			else if (format[i] == '\0')
				return (-1);
			else
			{
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}

	va_end(args);
	return (count);
}

/**
 * _printf - simple printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    int num;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
        {
            num = va_arg(args, int);
            count += print_number(num);
            i += 2;
        }
        else
        {
            write(1, &format[i], 1);
            count++;
            i++;
        }
    }

    va_end(args);
    return (count);
}
