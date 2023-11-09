#include "shell.h"

/**
 * simple_env - A function that prints environment variables
 * @henv: The argument - represents an array of strings
 */

void simple_env(char **henv)
{
	/* Iterate through the environment variable until it is NULL*/
	while (*henv != NULL)
	{
		/* Print the current environment variable. */
		write(1, *henv, strlen(*henv));
		/* Print a newline character to separate the variables. */
		write(1, "\n", 1);
		/* Move to the next environment variable. */
		henv++;
	}
}
