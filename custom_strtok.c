#include "shell.h"

/* Custom strtok replacement function */
char *custom_strtok(char *str, const char *delim)
{
	char *token_start;
	static char *next_token = NULL;
	char *token_end;

	if (str != NULL)
	{
		next_token = str;
	}
	else if (next_token == NULL)
	{
		return (NULL);
	}

	token_start = next_token;
	token_end = strpbrk(next_token, delim);

	if (token_end != NULL)
	{
		*token_end = '\0';
		next_token = token_end + 1;
	}
	else
	{
		next_token = NULL;
	}

	return (token_start);
}
