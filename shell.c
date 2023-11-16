#include "shell.h"

/**
 * main - Entry point for the custom shell program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * @env: Array of environment variable strings.
 *
 * This function initializes the shell, reads user input,
 * and executes commands in a loop.
 *
 * Return: Always returns 0.
 */
int main(int argc, char *argv[], char **env)
{
	char *buffer;
	(void)argc;

	while (1)
	{
		user_prompt();
		buffer = read_input();
		execute_input(buffer, argv, env);
		free(buffer);
	}

	return (0);
}
