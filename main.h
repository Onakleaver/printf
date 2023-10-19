#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _putchar(char c);
int handle_specifier(char specifier, va_list args);
int _strlen(const char *str);
int _itoa(int num, char *buffer);
int _utoa(unsigned int num, char *buffer);
int _ptoa(void *ptr, char *buffer);

#endif
