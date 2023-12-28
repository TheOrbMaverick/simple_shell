#include "shell.h"
#define BUFFER_SIZE 1024

/**
 * my_getline - Custom getline function for a simple shell
 * @lineptr: Address of the buffer to store the input
 * @n: Address of the buffer size
 * @stream: File stream (e.g., stdin)
 *
 * Return: Number of characters read (including newline), or -1 on failure
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static int position = 0;
	static int characters_read = 0;

	char *line = NULL;
	int c;

	if (lineptr == NULL || n == NULL)
	{
		errno = EINVAL; // Invalid argument
		return -1;
	}

	while (1)
	{
		// If the buffer is empty or all characters have been read, refill it
		if (position == characters_read)
		{
			position = 0;
			characters_read = read(fileno(stream), buffer, BUFFER_SIZE);

			if (characters_read <= 0)
			{
				// End of file or error, return -1 to indicate failure
				return (-1);
			}
		}

		c = buffer[position++];

		// Allocate memory for the line and append characters until a newline or end of buffer
		if (line == NULL)
		{
			line = malloc(1);
			line[0] = '\0';
		}

		if (c == EOF || c == '\n')
		{
			break; // End of line
		}

		char *temp = realloc(line, strlen(line) + 2);
		if (temp == NULL)
		{
			free(line);
			perror("Error: Unable to allocate memory");
			exit(EXIT_FAILURE);
		}

		line = temp;
		line[strlen(line)] = c;
		line[strlen(line) + 1] = '\0';
	}

	// Update the buffer size and set the lineptr to the allocated memory
	*n = strlen(line) + 1;
	*lineptr = line;

	return (*n);
}