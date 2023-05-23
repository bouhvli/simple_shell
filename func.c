#include "main.h"
/**
 * _printf - print function to raplace printf.
 * @str: the string we want to display.
 * @stream: the stream type.
 */
void _printf(char *str, int stream)
{
	int i = 0;

	while (*(str + i) != '\0')
	{
		write(stream, &str[i], 1);
		i++;
	}
}
/**
 * tokenization - getting all the tokens from token.
 * @token: pointer to the the first character of the input string.
 * @tokens: where we want to store the tokes.
 */
void tokenization(char *token, char *tokens[])
{
	int token_count = 0, i;

	while (token != NULL && token_count < MAX_TOKENS)
	{
		tokens[token_count++] = _strdup(token);
		token = strtok(NULL, " ");
	}
	for (i = token_count; i < MAX_TOKENS; i++)
		tokens[i] = NULL;
	tokens[token_count++] = NULL;
}
/**
 * _free_tokens - take care of the memory leaks that may come from tokens
 * pointer.
 * @token_count: the number of tokens.
 * @tokens: the tokens array.
 *
 * Return: the number of tokens.
 */
int _free_tokens(int token_count, char *tokens[])
{
	int i;

	for (i = 0; i < token_count; i++)
	{
		if (tokens[i] != NULL)
		{
			free(tokens[i]);
		}
	}
	token_count = 0;
	return (token_count);
}
/**
 * _fork_exec - where the execution of the command live and do the work.
 * @cmd: the command.
 * @tokens: the tokens array.
 * @count: nomber of tokens.
 * @av: the shell name.
 * @i: the number of command.
 */
void _fork_exec(char *cmd, char *tokens[], int count, char *av, int i)
{
	int st;
	pid_t pro;

	if (cmd != NULL && exit_status != 127)
	{
		pro = fork();
		if (pro == 0)
		{
			if (execve(cmd, tokens, NULL))
			{
				_error(cmd, av, i);
			}
		}
		else
		{
			wait(&st);
			if (WIFEXITED(st))
			{
				count = _free_tokens(count, tokens);
				exit_status = WEXITSTATUS(st);
            }
		}
		free(cmd);
	}
	else
	{
	count = _free_tokens(count, tokens);
	free(cmd);
	
	}
}
/**
 * _error - print the error message.
 * @cmd: the command.
 * @av: the name of the shell.
 * @count: the number of the command.
 */
void _error(char *cmd, char *av, int count)
{
	char *y = int_to_string(count);

	_printf(av, 2);
	_printf(": ", 2);
	_printf(y, 2);
	_printf(": ", 2);
	_printf(cmd, 2);
	_printf(": not found", 2);
	_printf("\n", 2);
	free(y);
}
/**
 * _exit_error : the error message in case the user give an exit
 * value that is not allowed.
 * @cmd: the command.
 * @av: the name of the shell.
 * @count: the number of the command.
 * @status: the exit status the user wanted to exit with.
*/
void _exit_error(char *cmd, char *av, int count, char *status)
{
	char *y = int_to_string(count);

	_printf(av, 2);
	_printf(": ", 2);
	_printf(y, 2);
	_printf(": ", 2);
	_printf(cmd, 2);
	_printf(": illegal number:", 2);
	_printf(status, 2);
	_printf("\n", 2);
	free(y);
}