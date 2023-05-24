#include "main.h"

/**
 * handleComment - handle if there is any comments in the given command.
 * @string: the string that holds the command.
 */

void handleComment(char *string)
{
	int i = 0;

	if (string[0] == '#')
	{
		string[0] = '\0';
	}
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			i++;
			if (string[i] == '#')
			{
				string[i] = '\0';
				break;
			}
		}
		if (string[i] != '\0')
			i++;
	}
}
