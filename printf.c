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
            char flags = 0;
            while (*format == '+' || *format == '-' || *format == ' ')
            {
                flags |= (*format == '+') ? 1 : 0;
                flags |= (*format == '-') ? 2 : 0;
                flags |= (*format == ' ') ? 4 : 0;
                format++;
            }

            switch (*format)
            {
            case 'd':
            case 'i':
            {
                int num = va_arg(args, int);
                char buffer[20];
                int len = snprintf(buffer, sizeof(buffer), "%+d", num); // Handle '+' flag
                if (flags & 2)
                {
                    // Handle '-' flag
                    write(1, buffer, len);
                    printed_chars += len;
                    int padding = 0;
                    while (padding++ < 10 - len)
                    {
                        write(1, " ", 1);
                        printed_chars++;
                    }
                }
                else if (flags & 4)
                {
                    // Handle ' ' flag
                    write(1, " ", 1);
                    printed_chars++;
                    int padding = 0;
                    while (padding++ < 10 - len)
                    {
                        write(1, " ", 1);
                        printed_chars++;
                    }
                }
                else
                {
                    write(1, buffer, len);
                    printed_chars += len;
                }
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
