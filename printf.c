#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (!format)
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
			case 'b':
			{
				unsigned int num = va_arg(args, unsigned int);
				print_binary(num);
				printed_chars += 32;
			}
			default:
				write(1, "%", 1);
				printed_chars++;
				break;
			}
		}
		format++;
	}

	va_end(args);
	return printed_chars;
}
