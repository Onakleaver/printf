#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int num_char = 0;

    while (*format) {
        if (*format != '%') {
            write(1, format, 1);
            num_char++;
        } else {
            format++;
            if (*format == 'c') {
                char c = va_arg(args, int);
                write(1, &c, 1);
                num_char++;
            } else if (*format == '%') {
                write(1, "%", 1);
                num_char++;
            } else if (*format == 's') {
                char *str = va_arg(args, char *);
                int len = 0;
                while (str[len] != '\0') {
                    len++;
                }
                write(1, str, len);
                num_char += len;
            }
        }
        format++;
    }

    va_end(args);
    return num_char;
}

int main() {
    my_printf("Hello, %c World! %s\n", 'C', "printf");
    my_printf("This is a test of %%d and %s\n", "my_printf");
    return 0;
}
