#include "main.h"
/**
 * handl_exit - Implement the exit built-in, that exits the shell.
 * @str: takes a string.
 * @status:the sxit status.
 * @av: the name of the shell.
 * @count: number of the command.
}*/
void handl_exit(char *str, int status, char *av, int count)
{
	int comp = _strcmp(str, "exit");
	char *string = _strdup(str);
	int val = 0, i = 0;
	char *token = strtok(string, " ");
	char *tokens[MAX_TOKENS] = {NULL};

	if (comp != 0 && _strcmp(token, "exit") == 0)
	{
		tokenization(token, tokens);
		if (_strcmp(tokens[0], "exit") == 0)
		{
				val = toNumber(tokens[1]);
				if (val <= 0)
				{
					_exit_error(tokens[0], av, count, tokens[1]);
					while (tokens[i] != NULL)
					{
						free(tokens[i]);
						i++;
					}
					free(str);
					free(string);
					exit(2);
				}
				else{
					while (tokens[i] != NULL)
					{
						free(tokens[i]);
						i++;
					}
					free(str);
					free(string);
					exit(val);
				}
		}
		else{
			while (tokens[i] != NULL)
			{
				free(tokens[i]);
				i++;
			}
			free(string);
		}
	}
	free(string);
	if (comp == 0)
	{
		if (status > 0)
		{
			free(str);
			exit(status);
		}
		else if (status < 0)
		{
			_printf("wrong", 2);
			free(str);
			exit(2);
		}
		else
		{
			free(str);
			exit(0);
		}
	}
}
/**
 * handl_env - prints all the environment variables.
 */
void handl_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_printf(environ[i], 1);
		_printf("\n", 1);
		i++;
	}
}
/**
 * handl_ctrl_d - handle the case where the user type CTRL-D
 * @n: takes a number.
 * @str: and a string.
 */
void handl_ctrl_d(int n, char *str)
{
	if (n == -1 || n == EOF)
	{
		free(str);
		exit(0);
	}
}
/**
 * toNumber - convert from a string to number
 * @string: thestring.
 * Return: the converted number.
 */
int toNumber(char *string)
{
	int sign = 1, i = 0, number = 0;

	while (string[i] == ' ' || string[i] == '\t' || string[i] == '\n' || string[i] == '\r')
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		number = number * 10 + (string[i] - '0');
		i++;
	}
	return (sign * number);
}