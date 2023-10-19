#include "main.h"

/**
 * _printf - Custom implementation of printf function.
 * @format: A format string with optional format specifiers.
 * @...: Variable number of arguments to replace format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 *         Returns -1 if format is NULL.
 */

int handle_specifier(char specifier, va_list args);
int _strlen(const char *str);
int _itoa(int num, char *buffer);
int _utoa(unsigned int num, char *buffer);
int _ptoa(void *ptr, char *buffer);

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (!format)
		return (-1);

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
			if (!*format)
				return (-1);

			printed_chars += handle_specifier(*format, args);
		}
		format++;
	}
	va_end(args);

	return (printed_chars);
}

/**
 * handle_specifier - Handles a format specifier.
 * @specifier: The format specifier character.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed.
 */
int handle_specifier(char specifier, va_list args)
{
	char *str;
	char buffer[20];
	int len;

	switch (specifier)
	{
	case 'c':
		char c = va_arg(args, int);

		write(1, &c, 1);
		return 1;
	case 's':
		str = va_arg(args, char *);
		write(1, str, _strlen(str));
		return _strlen(str);
	case 'd':
	case 'i':
		len = _itoa(va_arg(args, int), buffer);
		write(1, buffer, len);
		return len;
	case 'u':
		len = _utoa(va_arg(args, unsigned int), buffer);
		write(1, buffer, len);
		return len;
	case 'p':
		len = _ptoa(va_arg(args, void *), buffer);
		write(1, buffer, len);
		return len;
	default:
		write(1, "%", 1);
		return 1;
	}
}

/**
 * _strlen - Custom implementation of strlen function.
 * @str: The string to measure.
 *
 * Return: The length of the string.
 */
int _strlen(const char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

/**
 * _itoa - Custom implementation of itoa function.
 * @num: The integer to convert to a string.
 * @buffer: The character buffer to store the result.
 *
 * Return: The length of the resulting string.
 */
int _itoa(int num, char *buffer)
{
	return sprintf(buffer, "%d", num);
}

/**
 * _utoa - Custom implementation of utoa function.
 * @num: The unsigned integer to convert to a string.
 * @buffer: The character buffer to store the result.
 *
 * Return: The length of the resulting string.
 */
int _utoa(unsigned int num, char *buffer)
{
	return sprintf(buffer, "%u", num);
}

/**
 * _ptoa - Custom implementation of ptoa function.
 * @ptr: The pointer to convert to a string.
 * @buffer: The character buffer to store the result.
 *
 * Return: The length of the resulting string.
 */
int _ptoa(void *ptr, char *buffer)
{
	return sprintf(buffer, "%p", ptr);
}
