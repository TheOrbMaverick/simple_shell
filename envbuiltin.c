#include "shell.h"

/**
 * simple_env - A function that prints environment variables
 * @env: The argument - represents an array of strings
 */

void simple_env(char **env)
{
	/* Iterate through the environment variable until it is NULL*/
	while (*env != NULL)
	{
		/* Print the current environment variable. */
		write(1, *env, strlen(*env));
		/* Print a newline character to separate the variables. */
		write(1, "\n", 1);
		/* Move to the next environment variable. */
		env++;
	}
}
