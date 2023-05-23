#include "main.h"
/**
 * handle_sigint - thandle the xase where the user typed CTRL-C
 * @sig: the signal number
*/
void handle_sigint(int sig)
{
	if (sig == SIGINT)
		_printf("\n#cisfun$ ", 1);
}
/**
 * main - the main func.
 * @ac:number of args.
 * @argv: the array of args
 * Return: 0 and -1 incase of error.
 */
int main(int ac, char *argv[])
{
	char *tokens[MAX_TOKENS] = {NULL};
	char *input_string = NULL;
	int token_count = 0, i = 0, val = 0, count = 0;
	char *token, *cmd_path;
	/*size_t n = 0;*/
	if (ac < 1)
		return (-1);
	for (;;)
	{
		fflush(stdin);
		signal(SIGINT, handle_sigint);
		count++;
		if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
			_printf("#cisfun$ ", 1);
		val = _getline(&input_string, STDIN_FILENO);
		/*val = getline(&input_string, &n, stdin);*/
		if (val == -1)
		{
			free(input_string);
			exit(0);
		}
		if (_strspn(input_string, " \t\n") == _strlen(input_string))
				continue;
		/*input_string[_strcspn(input_string, "\n")] = '\0';*/
		handl_exit(input_string, exit_status, argv[0], count);
		handl_ctrl_d(val, input_string);
		if (_strcmp(input_string, "env") == 0)
			handl_env();
		else
		{
			token = strtok(input_string, " ");
			tokenization(token, tokens);
			cmd_path = path_finder(tokens[0], argv[0], count);
			_fork_exec(cmd_path, tokens, token_count, argv[0], count);
			i = 0;
			while (tokens[i] != NULL)
				free(tokens[i++]);
			if ((isatty(STDIN_FILENO) == 0) && exit_status == 127)
				{
				free(input_string);
				exit(exit_status);
				}
		}
	}
	free(token);
	free(cmd_path);
	free(input_string);
	return (0);
}

