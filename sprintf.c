#include "main.h"

/**
 * write_char - writes a char to the stream passed
 * @p: a double pointer to the stream
 * @ch: character to write
 * @count: the number of byte written
 * Return: void
 */

void write_char(char **p, char ch, int *count)
{
	**p = ch;
	(*p)++;
	(*count)++;
}

/**
 * write_str - writes a string to a stream
 * @p: double pointer to the stream
 * @str: the string to write
 * @count: the number of byte written
 * Return: void
 */

void write_str(char **p, const char *str, int *count)
{
	while (*str != '\0')
	{
		**p = *str;
		(*p)++;
		str++;
		(*count)++;
	}
}

/**
 * write_int - writes a number to a steam
 * @p: double pointer to the string to write to stream
 * @num: the number to write to stream
 * @count: the number of byte written
 * Return: void
 */

void write_int(char **p, int num, int *count)
{
	char buf[32];
	int i = 0;

	if (num < 0)
	{
		write_char(p, '-', count);
		num = -num;
	}
	do {
		buf[i++] = (num % 10) + '0';
		num /= 10;
	} while (num != 0);
	while (i > 0)
	{
		i--;
		write_char(p, buf[i], count);
	}
	(*count)++;
}

/**
 * write_float - writes a float to a stream
 * @p: a double pointer to the stream
 * @num: the number to be writen to the stream
 * @count: the number of byte written
 * Return: the number of item written to num
 */

void write_float(char **p, double num, int *count)
{
	int whole = (int) num, i, digit;
	double frac = num - whole;

	write_int(p, whole, count);
	write_char(p, '.', count);
	for (i = 0; i < 6; i++)
	{
		frac *= 10.0;
		digit = (int) frac;
		frac -= digit;
		write_char(p, digit + '0', count);
	}
	(*count)++;
}

/**
 * _sprintf - writes to a stream
 * @str: the stream
 * @format: the string to write
 * Return: number of format string writen
 */

int _sprintf(char *str, const char *format, ...)
{
	char *p = str;
	const char *c;
	int count = 0;
	va_list args;

	va_start(args, format);
	for (c = format; *c != '\0'; c++)
	{
		if (*c == '%')
		{	c++;
			switch (*c)
			{	case 'c':
					{	char ch = (char) va_arg(args, int);

						write_char(&p, ch, &count);
						break; }
				case 's':
					{	char *s = va_arg(args, char*);

						write_str(&p, s, &count);
						break; }
				case 'd':
					{	int num = va_arg(args, int);

						write_int(&p, num, &count);
						break; }
				case 'f':
					{	double num = va_arg(args, double);

						write_float(&p, num, &count);
						break; }
				default:
					break; }
		}
		else
			write_char(&p, *c, &count);
	}
	write_char(&p, '\0', &count);
	va_end(args);
	return (count);
}
