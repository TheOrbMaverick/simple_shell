#include "shell.h"

/**
 * main - Entry point for the custom shell program.
 *
 * This function initializes the shell, reads user input,
 * and executes commands in a loop.
 *
 * Return: Always returns 0.
 */

int main(int argc, char *argv[], char **env)
{
	char *input_buffer;
	(void)argc;

	while (1)
	{
		user_prompt();
		input_buffer = read_input();
		execute_input(input_buffer, argv, env);
		free(input_buffer);
	}

	return (0);
}
