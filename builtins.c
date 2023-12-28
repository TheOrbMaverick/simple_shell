#include "shell.h"

/**
  * env_print - Prints the environment variables
  * @env: Arguments
  */

void env_print(char **env)
{
	while (*env != NULL)
	{
		write(1, *env, strlen(*env));
		write(1, "\n", 1);
		env++;
	}
}


/**
  * exit_handler - Handles the exit functionality
  * @user_input: user_input value to handle
  * @exit_stat: Exit status of the code
  */

void exit_handler(char *user_input, int exit_stat)
{
	free(user_input);
	exit(exit_stat);
}

/**
  * exit_shell - Handles the exit built-in command
  * @args: Arguments to the exit command (not used in this case)
  * @user_input: The user_input command (not used in this case)
  *
  * Return: This function does not return; it exits the shell
  */

void exit_shell(char **args, char *user_input)
{
    (void)args; // Silence unused parameter warning
    free(user_input);
    exit(0);
}

/**
  * change_directory - Handles the cd functionality
  * @args: Array of commands
  * @num_of_args: Argument count
  */

void change_directory(char **args, int num_of_args)
{
	const char *home_directory, *pre_directory;

	home_directory = getenv("HOME");
	pre_directory = getenv("OLDPWD");

	if (num_of_args == 1 || strcmp(args[1], "~") == 0)
	{
		if (!home_directory)
		{
			perror("Home environment not set");
			return;
		}
		if (chdir(home_directory) != 0)
			perror("cd");
	}
	else if (num_of_args == 2 && strcmp(args[1], "-") == 0)
	{
		if (!pre_directory)
		{
			perror("OLDPWD environment not set");
			return;
		}
		if (chdir(pre_directory) != 0)
			perror("cd");
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
}
