#include "shell.h"

void display_prompt(void)
{
	printf("#cisfun$ ");
}

char *read_input(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	printf("#cisfun$ ");
	
	/* Using fgets as a replacement for getline */
	if (fgets(buffer, bufsize, stdin) == NULL)
	{
		if (feof(stdin))  /* Check for end-of-file condition (Ctrl+D) */
		{
			printf("\n");
			free(buffer);
			exit(EXIT_SUCCESS);  /* Exit the program on Ctrl+D */
		}
		else
		{
			perror("fgets");
			free(buffer);
			exit(EXIT_FAILURE);
		}
	}

	buffer[strcspn(buffer, "\n")] = '\0';  /* Remove the newline character from the input */
	return (buffer);
}

void execute_command(char *command)
{
	pid_t pid;  /* Declare pid at the beginning of the block */
	char *args[64];  /* Assuming a maximum of 64 arguments */
	int i = 0;
	char *token = command;

	while (*token != '\0' && i < 64)
	{
		char *space = strpbrk(token, " ");

		if (space != NULL)
		{
			*space = '\0';
			args[i++] = token;
			token = space + 1;
		}
		else
		{
			args[i++] = token;
			break;
		}
	}

	args[i] = NULL;

	pid = fork();  /* Create a child process */

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)  /* Child process */
	{
		char *envp[] = {NULL};  /* You can modify this if you need to set environment variables */

		execve(args[0], args, envp);  /* Execute the command with arguments and environment variables */

		/* If execve fails */
		perror("execve");
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
