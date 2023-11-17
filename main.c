#include "shell.h"

/**
 * main - Entry point for the shell program.
 *
 * Return: Always returns 0.
 */

int main(void)
{
	char *user_input;

	while (1)
	{
		display_prompt();  /* Display the prompt to the user */
		user_input = read_input();

		if (user_input == NULL)
		{
			/* Handle Ctrl+D or other exit conditions */
			break;
		}

		execute_command(user_input);

		free(user_input);
	}

	return (0);
}
