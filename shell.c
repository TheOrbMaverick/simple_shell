#include "shell.h"

void display_prompt(void)
{
	printf("#cisfun$ ");
}

char *read_input(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	if (getline(&buffer, &bufsize, stdin) == -1)
	{
		if (feof(stdin))  /* Check for end-of-file condition (Ctrl+D) */
		{
			printf("\n");
			free(buffer);
			exit(EXIT_SUCCESS);  /* Exit the program on Ctrl+D */
		}
		else
		{
			perror("getline");
			free(buffer);
			exit(EXIT_FAILURE);
		}
	}

	buffer[strcspn(buffer, "\n")] = '\0';  /* Remove the newline character from the input */
	return (buffer);
}

void execute_command(char *command)
{
	char *token;  /* Tokenize the input to separate command and arguments */
	pid_t pid;

	token = strtok(command, " ");

	if (token == NULL)
	{
		fprintf(stderr, "No command entered.\n");
		return;
	}

	pid = fork();  /* Create a child process */

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)  /* Child process */
	{
		char *args[64];  /* Assuming a maximum of 64 arguments */
		int i = 0;

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}

		args[i] = NULL;

		execvp(args[0], args);  /* Execute the command with arguments */

		/* If execvp fails */
		perror("execvp");
		_exit(EXIT_FAILURE);
	}
	else  /* Parent process */
	{
		int status;
		waitpid(pid, &status, 0);  /* Wait for the child process to complete */

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "./shell: %s: command not found\n", command);
		}
	}
}
