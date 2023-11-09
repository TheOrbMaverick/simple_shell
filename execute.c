#include "shell.h"

/**
 * execute_input - Execute a command specified by the user input.
 * @user_input: The command entered by the user.
 *
 * This function creates a child process using fork and then uses execve to
 * execute the command specified by the user's input. It waits for the child
 * process to complete before returning.
 */

void execute_input(char *user_input)
{
	char *token;
	const char *command;
	char *path, *path_copy, *path_dir, *env, command_path[PATH_MAX];
	pid_t pid;

	/* Remove trailing newline character if present */
	size_t len = strlen(user_input);

	if (user_input[len - 1] == '\n')
	{
		user_input[len - 1] = '\0';
	}

	/* Tokenize the user input into command and arguments */
	token = strtok(user_input, " ");
	if (token == NULL)
	{
		return; /* Empty input, nothing to execute */
	}

	/* The first token is the command */
	command = token;

	if (strcmp(command, "exit") == 0)
	{
		/* Handle "exit" command */
		exit(EXIT_SUCCESS);
		
	} else if (strcmp(command, "env") == 0)
	{
		/* Handle "env" command */
		env = getenv("PATH");
		if (env != NULL)
		{
			our_printf("%s\n", env);
		} else
		{
			our_printf("PATH environment variable not found\n");
		}
		return;
	}

	/* Check if the command exists in the PATH */
	path = getenv("PATH");
	path_copy = strdup(path);
	path_dir = strtok(path_copy, ":");

	while (path_dir != NULL)
	{
		snprintf(command_path, PATH_MAX, "%s/%s", path_dir, command);
		if (access(command_path, X_OK) == 0)
		{
			/* The command exists in this directory, proceed to execute */
			free(path_copy);

			pid = fork();

			if (pid == -1)
			{
				/* Error handling: fork failed */
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				/* Child process */

				/* Create an array of arguments for execve */
				char *args[256];
				int i = 0;

				args[i++] = (char *)command; /* The first argument is the command */

				/* Copy the remaining arguments into the args array */
				while ((token = strtok(NULL, " ")) != NULL && i < 255)
				{
					args[i++] = token;
				}
				args[i] = NULL; /* Ensure the last element is NULL */

				/* Replace the child process with the command */
				execve(command_path, args, NULL);

				/* execve will only return if there is an error */
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				/* Parent process */
				wait(NULL);
				return;
			}
		}

		path_dir = strtok(NULL, ":");
	}

	/* If the loop finishes, the command does not exist in any PATH directory */
	free(path_copy);
	our_printf("Command not found: %s\n", command);
}
