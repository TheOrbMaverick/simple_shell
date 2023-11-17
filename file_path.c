#include "shell.h"

/**
 * f_path - Get the full path of a command.
 * @name: The name of the command.
 *
 * This function returns the full path of the specified command by searching
 * for it in the directories listed in the PATH environment variable.
 * If the command is found and is executable, its full path is returned.
 * If not found or not executable, an error message is printed to stderr.
 *
 * Returns: On success, the full path of the command. On failure, NULL.
 */

char *f_path(const char *name)
{
	char *main_path;
	char *complete_path;

	main_path = getenv("PATH");

	if (forward_slash(name) && access(name, X_OK) == 0)
	{
		return (strdup(name));
	}
	else if (!main_path)
	{
		perror("Path does not exist");
		return (NULL);
	}

	complete_path = find_file(main_path, name);

	if (complete_path == NULL)
	{
		write(2, name, strlen(name));
		write(2, ": command not found\n", 19);
		return (NULL);
	}
	/* returns the complete path*/
	return (complete_path);
}

/**
 * forward_slash - Check if a string starts with a forward slash.
 * @str: The string to check.
 *
 * This function checks if the given string starts with a forward slash.
 *
 * Returns: 1 if the string starts with a forward slash, otherwise 0.
 */

int forward_slash(const char *str)
{
	if (str != NULL && str[0] == '/')
	{
		/* returns success forward slash */
		return (1);
	}
	/* exits if there it does not begin with forward slash*/
	return (0);
}
