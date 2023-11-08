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
	const char *dir_home, *last_dir;

	dir_home = getenv("HOME");
	last_dir = getenv("OLDPWD");

	if (nof_args == 1 || strcmp(args[1], "~") == 0)
	{
		if (!dir_home)
		{
			perror("Hi,Home environment not active");
			return;
		}
		if (chdir(dir_home) != 0)
			perror("cd");
	}
	else if (nof_args == 2 && strcmp(args[1], "-") == 0)
	{
		if (!last_dir)
		{
			perror("Hi, OLDPWD environment not active");
			return;
		}
		if (chdir(last_dir) != 0)
			perror("cd");
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
}
