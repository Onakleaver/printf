#include "main.h"


int _printf(const char *format, ...)
{
    int num_char = 0;

    va_list arg_list;
    
    if(!format)
    {
        return (-1);
    }
    
    var_start(arg_list, format);
    
    {
        while(*format != '\0')
        {
            if (*format != '%')
            {
                write(1, &format, 1);
                num_char++;
                format++;
        //check for %(it is not there)
        // writes output to the stdio
        //return number of characters printed
            }
            else
            {
                format++;
                if (format = 'c')
                {
                    char c = va_arg(arg_list, char);
                    write(1, &c, 1);
                    num_char++;
                }
                else if (format = '%')
                {
                    char c = va_arg(arg_list, char);
                    write(1, &c, 1);
                    num_char++;
                }
                else
                {
                    char *str = va_arg(arg_list, char*);
                    int len = 0;
                }
        //check for %(exists)
        //check if the next character is c, s, or %
        //if c va_arg
        // if null
        // if string. count characters and also print
        // writes output to the stdio
        //return number of characters printed
            }
            return (num_char);
        }

    }


    va_end(arg_list);
}