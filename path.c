#include "main.h"
/**
 * path_finder - this function finds the path and return it
 * @tokens: the command.
 * @s: the shell name.
 * @count:the number of command
 * Return: NULL if path is not found or if an error occured,
 * or return THE path with the command.
 */
char *path_finder(char *tokens, char *s, int count)
{
	char *dir, *full_path, *p, *sl, *command = _strdup(tokens);
	char *path = _getenv("PATH"), *command_path = NULL;

	if (path == NULL || _strcmp(path, "") == 0)
	{
		if (access(command, X_OK | F_OK) == 0)
		{
			return (command);
		}
		else
		{
			_error(command, s, count);
			exit(127);
		}
	}
	while (*path)
	{
		dir = malloc(MAX_TOKEN_LENGTH);
		p = _strchr(path, ':');
		if (p == NULL)
		{
			_strcpy(dir, path);
			path += _strlen(path);
		}
		else
		{
			_strncpy(dir, path, p - path);
			dir[p - path] = '\0';
			path = p + 1;
		}
		sl = _strchr(command, '/');
		if (sl == NULL)
		{
			full_path = malloc(MAX_TOKEN_LENGTH);
			_sprintf(full_path, "%s/%s", dir, command);
		}
		else
			full_path = _strdup(command);
		if (access(full_path, X_OK | F_OK) == 0)
		{
			command_path = _strdup(full_path);
			free(dir), free(full_path);
			break;
		}
		free(dir), free(full_path);
	}
	if (command_path == NULL)
	{
		_error(command, s, count), free(command);
		exit_status = 127;
		return (NULL);
	}
	free(command);
	return (command_path);
}

