#include "shell.h"

/**
  * builtin_cmd - Handle all the built in commands
  * @args: Arguments to the built in commands
  * @num_args: Number of argument
  * @input: The input command
  * @env: The environment variables
  *
  * Return: 1 if successful 0, if unsuccessful
  */

int builtin_cmd(char **args, int num_args, char *input, char **env)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (exit_shell(args, input));
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		cd_input(args, num_args);
		return (1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		environs_print(env);
		return (1);
	}

	return (0);
}