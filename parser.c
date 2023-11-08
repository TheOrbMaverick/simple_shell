#include "shell.h"

/**
 * read_input - Read user input into a buffer.
 * @user_input: A buffer to store user input.
 * @size: Maximum size of the user_input buffer.
 *
 * Returns: No return value.
 */

void read_input(char *user_input, size_t size)
{
	/* Read user input from stdin */
	if (fgets(user_input, size, stdin) == NULL)
	{
		/* Check if an enf-of-file condition is encountered */
		if (feof(stdin))
		{
			/* Display a newline to improve output formatting */
			our_printf("\n");
			/* Exit program with a success status */
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* Handle input error and prompt user to retry */
			our_printf("Input error please retry.");
			/* Exit program with failure status */
			exit(EXIT_FAILURE);
		}
	}
}
