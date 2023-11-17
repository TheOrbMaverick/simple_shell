#include "shell.h"

/**
 * main - Entry point of the program
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 *
 * Return: Always 0 (success)
 */
/* int main(int argc, char **argv) */

int main(void)
{
	char *line = NULL;  /* Pointer to store input line */
	size_t len = 0;     /* Length of the input line */

	/* Print the initial prompt */
	printf("$ ");

	/* Read input lines until end-of-file is encountered */
	while (getline(&line, &len, stdin) != -1)
	{
		/* Check for end-of-file */
		if (feof(stdin))
		{
			printf("\nEnd of input. Exiting.\n");
			break;
		}

		/* Print the entered command */
		printf(" %s", line);

		/* Loop through command line arguments */
		/*
		* for (int i = 0; i < argc; ++i)
		*	{
		*		printf("av[%d]: %s\n", i, argv[i]);
		*	}
		*/
		

		/* Print the next prompt */
		printf("$ ");
	}

	free(line);  /* Free the allocated memory for the line */

	return (0);  /* Exit the program with success status */
}
