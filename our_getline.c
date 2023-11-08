#include "shell.h"

/**
 * simple_getline - Function reads input from input stream
 * and stores in buffer
 * @input_stream: A buffer
 * Return: buffer containing user input
 */
char *simple_getline(FILE *input_stream)
{
	char *line_input;
	ssize_t read;
	size_t buf_size;

	line_input = NULL;
	buf_size = 0;
	read = getline(&line_input, &buf_size, input_stream);
	if (read == -1)
	{
		free(line_input);
		exit(EXIT_SUCCESS);
	}

	return (line_input);
}
