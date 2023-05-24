#include "main.h"

/**
 * _strcmp - compares two strings
 * @str1: The first string
 * @str2: the second string
 * Return: 0 if both string are same. Otherwise the diff btw str1 and str2
 */

int _strcmp(char *str1, char *str2)
{
	int idx = 0;

	while (str1[idx] != '\0' && str2[idx] != '\0' && str1[idx] == str2[idx])
		idx++;

	return (str1[idx] - str2[idx]);
}


/**
 * _strcpy - copy a string into another string
 * @dest: the location
 * @src: the string to copy
 * Return: a pointer to the copied string.
 */

char *_strcpy(char *dest, char *src)
{
	int idx = 0;

	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

/**
 * _strncpy - copy's n number of character from one string to another
 * @dest: the string we copy to
 * @src: the string to come from
 * @num: the number of string to copy
 * Return: a pointer to copied string
 */

char *_strncpy(char *dest, const char *src, size_t num)
{
	size_t idx;

	for (idx = 0; idx < num && src[idx] != '\0'; idx++)
	{
		dest[idx] = src[idx];
	}
	for (; idx < num; idx++)
	{
		dest[idx] = '\0';
	}
	return (dest);
}


/**
 * _strdup - duplicates a string
 * @src: the string to duplicate
 * Return: a pointer to the copied string
 */

char *_strdup(char *src)
{
	size_t idx, len = _strlen(src);
	char *dest = malloc(len + 1);

	if (dest == NULL)
		return (NULL);
	for (idx = 0; idx <= len; idx++)
		dest[idx] = src[idx];
	return (dest);
}

/**
 * _strlen - computes the lenght of a string
 * @str: the string
 * Return: the lenght of a string
 */

int _strlen(char *str)
{
	size_t count = 0;

	if (str == NULL)
	{
		return (0);
	}
	while (str[count] != 0)
		count++;
	return (count);
}
