#include "shell.h"

/**
  * user_prompt - Print the prompt to the user
  */

void user_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "MyShell$ ", 9);
}

/**
  * user_input_reader - Reads the input from the users
  *
  * Return: Character variable to the program
  */

char *user_input_reader(void)
{
	char *temp_input_storage;
	size_t buf_size;
	ssize_t nread;

	temp_input_storage = NULL;
	buf_size = 0;
	nread = getline(&temp_input_storage, &buf_size, stdin);

	if (nread == -1)
	{
		free(temp_input_storage);
		exit(0);
	}

	temp_input_storage = user_comment(temp_input_storage);

	return (temp_input_storage);
}


/**
  * cmd_exe - Executes the input from the buffer
  * @input: The argument from the buffer
  * @argv: Array of argument
  * @env: Environment variables
  */

void cmd_exe(char *input, char *argv[], char **env)
{
	char *args[10];
	char *path, *shell_name;
	int status, num_args;
	pid_t child_pid;

	shell_name = argv[0];
	num_args = tokenizer(input, args);

	if (num_args == 0)
		return;
	if (builtin(args, num_args, input, env) == 1)
		return;
	path = file_path(args[0]);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: Failed to create");
		free(input);
		exit(1);
	}

	if (child_pid == 0)
	{
		if (execve(path, args, NULL) == -1)
		{
			write(2, shell_name, strlen(shell_name));
			write(2, ": 1: ", 5);
			write(2, args[0], strlen(args[0]));
			write(2, ": not found\n", 12);
			exit(127);
		}
	}
	else
		wait(&status);

	free(path);
}

/**
  * tokenizer - Tokenizes the input strings
  * @input: Argument input
  * @args: The array of strings
  *
  * Return: Number of the items tokenized
  */

int tokenizer(char *input, char *args[])
{
	int count;
	char *token;

	count = 0;
	token = strtok(input, " \n");

	while (token)
	{
		args[count] = token;
		token = strtok(NULL, " \n");
		count++;
	}

	args[count] = NULL;
	return (count);
}

/**
  * builtin - Handle all the built in commands
  * @args: Arguments to the built in commands
  * @num_args: Number of argument
  * @input: The input command
  * @env: The environment variables
  *
  * Return: 1 if successful 0, if unsuccessful
  */

int builtin(char **args, int num_args, char *input, char **env)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (exit_shell(args, input));
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		change_directory(args, num_args);
		return (1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		env_print(env);
		return (1);
	}

	return (0);
}
