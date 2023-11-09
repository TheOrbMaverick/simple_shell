#include "shell.h"

/**
 * simple_getline - Function reads input from input stream
 * and stores in buffer
 * @input_stream: A buffer
 * Return: buffer containing user input
 */
char *simple_getline(FILE *input_stream)
{
	/* Declare a pointer to a character string to store the input line. */
	char *line_input;

	ssize_t read;
	size_t buf_size;

	/* Initialize 'line_input' to NULL for proper memory allocation by getline. */
	line_input = NULL;
	buf_size = 0;

	/* Read a line from the 'input_stream' into 'line_input' using getline. */
	read = getline(&line_input, &buf_size, input_stream);

	/* Check if getline returns -1, indicating an error or end of file. */
	if (read == -1)
	{
		/* Free the memory allocated for 'line_input'. */
		free(line_input);

		/* Exit the program with a successful status code. */
		exit(EXIT_SUCCESS);
	}

	return (line_input);
}
