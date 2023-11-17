#include "shell.h"

/**
 * main - Entry point for the shell program.
 *
 * Return: Always returns 0.
 */

#define MAX_COMMAND_LENGTH 100

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[2];
	pid_t pid;

	while (1)
	{
		my_printf("#cisfun$ ");

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			/* Handle Ctrl+D or other exit conditions */
			my_printf("\n");
			break;
		}

		/* Remove newline character */
		command[strcspn(command, "\n")] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)  /* Child process */
		{
			args[0] = command;
			args[1] = NULL;

			execve(command, args, NULL);

			/* If exec fails */
			perror(command);
			exit(EXIT_FAILURE);
		}
		else  /* Parent process */
		{
			int status;
			waitpid(pid, &status, 0);

			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			{
				fprintf(stderr, "./simple_shell: %s: command not found\n", command);
			}
		}
	}

	return (0);
}
