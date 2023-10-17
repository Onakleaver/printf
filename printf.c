#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
  
    char token[1000];
    int k = 0;
	int i;
  
    for (i = 0; format[i] != '\0'; i++) {
        token[k++] = format[i];
  
        if (format[i + 1] == '%' || format[i + 1] == '\0') {
            token[k] = '\0';
            k = 0;
            if (token[0] != '%') {
                fprintf(stdout, "%s", token);
            } else {
                int j = 1;
                char ch1 = 0;
  
                while ((ch1 = token[j++]) < 58) {
                }
                if (ch1 == 'i' || ch1 == 'd' || ch1 == 'u' || ch1 == 'h') {
                    fprintf(stdout, token, va_arg(args, int));
                } else if (ch1 == 'c') {
                    fprintf(stdout, token, va_arg(args, int));
                } else if (ch1 == 'f') {
                    fprintf(stdout, token, va_arg(args, double));
                } else if (ch1 == 'l') {
                    char ch2 = token[2];
                    if (ch2 == 'u' || ch2 == 'd' || ch2 == 'i') {
                        fprintf(stdout, token, va_arg(args, long));
                    } else if (ch2 == 'f') {
                        fprintf(stdout, token, va_arg(args, double));
                    }
                } else if (ch1 == 'L') {
                    char ch2 = token[2];
                    if (ch2 == 'u' || ch2 == 'd' || ch2 == 'i') {
                        fprintf(stdout, token, va_arg(args, long long));
                    } else if (ch2 == 'f') {
                        fprintf(stdout, token, va_arg(args, long double));
                    }
                } else if (ch1 == 's') {
                    fprintf(stdout, token, va_arg(args, char*));
                } else {
                    fprintf(stdout, "%s", token);
                }
            }
        }
    }
  
    va_end(args);
    return 0;
}

