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
  * input_reader - Reads the input from the users
  *
  * Return: Character variable to the program
  */

char *input_reader(void)
{
	char *input_buffer;
	size_t buf_size;
	ssize_t nread;

	input_buffer = NULL;
	buf_size = 0;
	nread = getline(&input_buffer, &buf_size, stdin);

	if (nread == -1)
	{
		free(input_buffer);
		exit(0);
	}

	input_buffer = handle_comment(input_buffer);

	return (input_buffer);
}


/**
  * exe_cmd - Executes the input from the buffer
  * @input: The argument from the buffer
  * @argv: Array of argument
  * @env: Environment variables
  */

void exe_cmd(char *input, char *argv[], char **env)
{
	char *args[10];
	char *path, *shell_name;
	int status, num_args;
	pid_t child_pid;

	shell_name = argv[0];
	num_args = tokenizer(input, args);

	if (num_args == 0)
		return;
	if (builtin_cmd(args, num_args, input, env) == 1)
		return;
	path = get_file_path(args[0]);

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
