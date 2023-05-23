#include "main.h"

/**
 * handleComment - handle if there is any comments in the given command.
 * @string: the string that holds the command.
 */

void handleComment(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		if (string[i] == '#')
		{
			string[i] = '\0';
			break;
		}
		i++;
	}
}
