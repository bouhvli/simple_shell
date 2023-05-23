#include "main.h"
/**
 * _strchr - searches a str for the first occurrence of a specified character.
 * @str: the string.
 * @c: the character.
 *
 * Return: returns a pointer to that character.
 */
char *_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}
/**
 * _strcspn - Identifies the length of the initial segment of the first
 *	string that does not contain any character from the second string.
 * @str1: the first string.
 * @str2: the second string.
 *
 * Return: if there is a match we will return the current value of idx,
 *	if no we return the final value of idx at the end of the functon.
 */
size_t _strcspn(const char *str1, const char *str2)
{
	const char *ptr1 = str1, *ptr2;
	size_t idx = 0;

	while (*ptr1)
	{
		ptr2 = str2;
		while (*ptr2)
		{
			if (*ptr1 == *ptr2)
				return (idx);
			++ptr2;
		}
		++ptr1;
		++idx;
	}
	return (idx);
}
/**
 * int_to_string - as the says.
 * @num: the number to convert.
 * Return: the converted number.
 */
char *int_to_string(int num)
{
	int temp = num;
	int size = 0, i;
	char *str;

	while (temp != 0)
	{
		size++;
		temp /= 10;
	}
	str = (char *)malloc((size + 1) * sizeof(char));
	for (i = size - 1; i >= 0; i--)
	{
		str[i] = num % 10 + '0';
		num /= 10;
	}
	str[size] = '\0';
	return (str);
}
/**
 * _strspn - get length of a prefix substring
 * @s: the string to check
 * @accept: the set of bytes to accept
 *
 * Return: the number of bytes in the initial segment of @s which
 *         consist only of bytes from @accept
 */
int _strspn(const char *s, const char *accept)
{
	const char *p;
	const char *a;
	int count = 0;

	if (s == NULL || accept == NULL)
		return (0);
	for (p = s; *p != '\0'; p++)
	{
		for (a = accept; *a != '\0'; a++)
		{
			if (*p == *a)
			{
				count++;
				break;
			}
		}
		if (*a == '\0')
		{
			return (count);
		}
	}
	return (count);
}

