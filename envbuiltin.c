#include "shell.h"

/**
 * simple_env - A function that prints environment variables
 * henv: The argument - represents an array of strings
 */

void simple_env(char **henv)
{
	/* Iterate through the environment variable until it is NULL*/
	while (*henv != NULL)
	{
		write(1, *henv, strlen(*henv));
		write(1, "\n", 1);
		henv++;
	}
}
