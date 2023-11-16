#include "shell.h"

/**
 * read_input - Read user input into a buffer.
 * Returns: A pointer to the user input buffer.
 */

char *read_input(void)
{
	size_t buf_size;
	ssize_t nread;
	char *buffer;

	buffer = NULL;
	buf_size = 0;
	nread = getline(&buffer, &buf_size, stdin);

	if (nread == -1)
	{
		free(buffer);
		exit(0);
	}

	/* You can add additional processing if needed */
	return (buffer);
}

