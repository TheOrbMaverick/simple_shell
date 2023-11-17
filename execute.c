#include "shell.h"

/**
 * execute_input - Execute a command specified by the user input.
 * @user_input: The command entered by the user.
 * @argv: An array of strings representing the arguments.
 * @env: The environment variables.
 *
 * This function creates a child process using fork and then uses execve to
 * execute the command specified by the user's input. It waits for the child
 * process to complete before returning.
 */

void execute_input(char *user_input, char *argv[], char **env)
{
	/* Declare variables */
	char *path, *args[10], *shell;
	pid_t baby_pid;
	int stat, numofargs;

	/* Set shell variable to the name of the shell */
	shell = argv[0];
	/* Tokenize user input into arguments */
	numofargs = tokenizer(user_input, args);

	/* If no arguments, return */
	if (numofargs == 0)
	{
		return;
	}

	/* Check if the command is a built-in command and execute if yes */
	if (func_builtin_commands(args, numofargs, user_input, env))
	{
		return;
	}

	/* Get the full path of the command */
	path = f_path(args[0]);

	/* Fork a child process */
	baby_pid = fork();

	/* Check for fork error */
	if (baby_pid == -1)
	{
		free(user_input);
		exit(1);
	}
	/* Child process */
	else if (baby_pid == 0)
	{
		/* Execute the command, and handle error if it fails */
		if (execve(path, args, NULL) == -1)
		{
			/* Check if not connected to a terminal (non-interactive mode) */
			if (!isatty(STDIN_FILENO))
			{
				exit(127);
			}
			else
			{
				write(2, shell, strlen(shell));
				exit(127);
			}
		}
	}
	/* Parent process */
	else
	{
		/* Wait for the child process to complete */
		wait(&stat);
	}
	/* Free the allocated path memory */
	free(path);
}
