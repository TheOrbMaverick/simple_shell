#include "shell.h"

/**
 * main - Entry point for the custom shell program.
 *
 * This function initializes the shell, reads user input,
 * and executes commands in a loop.
 *
 * Return: Always returns 0.
 */

int main(void)
{
	char user_input[256];

	while (1)
	{
		/* Display the custom shell prompt */
		user_prompt();
		/* Read user input */
		read_input(user_input, sizeof(user_input));
		/* Execute the user input as a command */
		execute_input(user_input);
	}
	return (0);
}
