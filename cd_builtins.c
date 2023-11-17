#include "shell.h"

/**
 * simple_cd - Change the current working directory.
 * @args: Array of command arguments.
 * @nof_args: The number of arguments.
 *
 * This function handles changing the current directory based on the provided
 * arguments. It can change to the home directory, the previous directory, or a
 * specific directory.
 */

void simple_cd(char **args, int nof_args)
{
	/* Declare pointers to store environment variables. */
	const char *dir_home, *last_dir;

	/* Retrieve the values of the HOME and OLDPWD environment variables */
	dir_home = getenv("HOME");
	last_dir = getenv("OLDPWD");

	/* Check if the number of arguments is 1 or the second argument is "~". */
	if (nof_args == 1 || strcmp(args[1], "~") == 0)
	{
		/* Check if the HOME environment variable is not set. */
		if (!dir_home)
		{
			/* Print an error message and return from the function. */
			perror("Hi,Home environment not active");
			return;
		}
		/* Attempt to change the current working directory to HOME. */
		if (chdir(dir_home) != 0)
			perror("cd");
	}
	/* Check if the number of arguments is 2 and the second argument is "-". */
	else if (nof_args == 2 && strcmp(args[1], "-") == 0)
	{
		/* Check if the OLDPWD environment variable is not set. */
		if (!last_dir)
		{
			perror("Hi, OLDPWD environment not active");
			return;
		}
		/* Attempt to change the current working directory to OLDPWD. */
		if (chdir(last_dir) != 0)
			perror("cd");
	}
	else
	{
		/* Attempt to change the current working directory to the specified path. */
		if (chdir(args[1]) != 0)
			perror("cd");
	}
}
