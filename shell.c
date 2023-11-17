#include "shell.h"

/**
 * display_prompt - Displays the shell prompt.
 */

void display_prompt(void)
{
	my_printf("#cisfun$ ");
}

/**
 * read_input - Reads user input from stdin.
 *
 * Return: A pointer to the user input buffer.
 */

char *read_input(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	if (getline(&buffer, &bufsize, stdin) == -1)
	{
		if (feof(stdin))  /* Check for end-of-file condition */
		{
			printf("\n");
			free(buffer);
			exit(EXIT_SUCCESS);
		} else
		{
			perror("getline");
			free(buffer);
			exit(EXIT_FAILURE);
		}
	}

	buffer[strcspn(buffer, "\n")] = '\0';
	return (buffer);
}

/**
 * execute_command - Executes a command.
 * @command: The command to be executed.
 *
 * Note: Implement command execution logic here.
 */

void execute_command(const char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)  /* Child process */
	{
		/* Parse command and arguments */
		char *args[64];
		char *token;
		int i = 0;

		token = strtok((char *)command, " ");
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}

		args[i] = NULL;

		execve(args[0], args, NULL);

		/* If execve fails */
		_exit(EXIT_FAILURE);

	} else  /* Parent process */
	{
		int status;
		waitpid(pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "./shell: %s: command not found\n", command);
		}
	}
}
