#include "shell.h"

/**
 * func_builtin_commands - Handle built-in shell commands.
 *
 * @args: An array of command arguments.
 * @nof_args: The number of arguments.
 * @val_put: The val_input command.
 * @env: The environment variables.
 *
 * This function handles built-in shell commands like 'exit', 'cd', and 'env'.
 * It executes the corresponding actions and returns status values.
 *
 * Return: 1 if a built-in command was executed, 0 otherwise.
 */

int func_builtin_commands(char **args, int nof_args, char *val_put, char **env)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (hell_exit(args, val_put));
	}
	else if (strcmp(args[0], "env") == 0)
	{
		simple_env(env);
		return (1);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		simple_cd(args, nof_args);
		return (1);
	}
	return (0);
}
