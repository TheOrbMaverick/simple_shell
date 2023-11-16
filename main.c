#include "shell.h"

/**
 * execute_input - Execute the user input as a command.
 * @user_input: User input containing the command.
 * @argv: Array of command-line argument strings.
 * @env: Array of environment variable strings.
 */

void execute_input(char *user_input, char *argv[], char **env)
{
	pid_t child_pid;
	int status;

	/* Fork a new process */
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		/* Child process */
		/* Execute the command */
		if (execve(user_input, argv, env) == -1)
		{
			/* Handle error */
			perror("execve");
			exit(EXIT_FAILURE);
		}
	} else
	{
		/* Parent process */
		/* Wait for the child to finish */
		if (waitpid(child_pid, &status, WUNTRACED) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}

		/* Check if the child process exited successfully */
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		{
			my_printf("Command executed successfully.\n");
		} else
		{
			my_printf("Error executing the command.\n");
		}
	}
}
