#include "main.h"

/**
 * _printf - Custom implementation of printf function.
 * @format: A format string with optional format specifiers.
 * @...: Variable number of arguments to replace format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 *         Returns -1 if format is NULL.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++;
			switch (*format)
			{
			case 'c':
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				printed_chars++;
				break;
			}
			case 's':
			{
				char *str = va_arg(args, char *);

				while (*str != '\0')
				{
					write(1, str, 1);
					str++;
					printed_chars++;
				}
				break;
			}
			case 'd': 
			case 'i':
			{
				int num = va_arg(args, int);
				char buffer[20];
				int len = snprintf(buffer, sizeof(buffer), "%d", num);

				write(1, buffer, len);
				printed_chars += len;
				break;
			}
			case 'u':
			{
				unsigned int num = va_arg(args, unsigned int);
				char buffer[20];
				int len = snprintf(buffer, sizeof(buffer), "%u", num);

				write(1, buffer, len);
				printed_chars += len;
				break;
			}
			case 'p':
			{
				void *ptr = va_arg(args, void *);
				char buffer[20];
				int len = snprintf(buffer, sizeof(buffer), "%p", ptr);

				write(1, buffer, len);
				printed_chars += len;
				break;
			}
			case '%':
			{
				write(1, "%", 1);
				printed_chars++;
				break;
			}
			default:
				break;
			}
		}
		format++;
	}

	va_end(args);
	return (printed_chars);
}
