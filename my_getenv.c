#include "main.h"

/**
 * _strncmp - compare defined number of bytes in two string.
 * @str1: the first string.
 * @str2: the second string to compare.
 * @n: the number of bytes to compare.
 * Return: -1 if there is no match and 0 if they are the same.
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i = 0;

	while (1 < n)
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}

/**
 * _getenv - get the environment variable the user wants.
 * @name: the name of the variable.
 * Return: NULL if it fails.
 */

char *_getenv(char *name)
{
	int i = 0;

	while (environ[i])
	{
		if (_strncmp(name, environ[i], _strlen(name)) == 0)
		{
			return (environ[i]);
		}
		i++;
	}
	return (NULL);
}
