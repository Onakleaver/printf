#include "main.h"

int _printf(const char *format, ...)
{
	int num_char = 0;
	va_list arg_list;

	if (!format)
	{
		return (-1);
	}
	va_start(arg_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			num_char++;
			format++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(arg_list, int);

				write(1, &c, 1);
				num_char++;
			}
			else if (*format == '\0')
			{
				break;
			}
			else if (*format == '%')
			{
				char c = va_arg(arg_list, int);

				write(1, &c, 1);
				num_char++;
			}
			else
			{
				char *str = va_arg(arg_list, char *);
				int len;

				for (len = 0; str[len] != '\0'; len++)
				{
					write(1, &str, str[len]);
					num_char++;
				}
			}
		}
		format++;
	}
	va_end(arg_list);
	return (num_char);
}
