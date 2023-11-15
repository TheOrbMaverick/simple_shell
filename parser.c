#include "shell.h"

/**
 * read_input - Read user input into a buffer.
 * @user_input: A buffer to store user input.
 * @size: Maximum size of the user_input buffer.
 *
 * Returns: No return value.
 */

int tokenizer(char *input, char *args[])
{
	char *token;
	int i;

	i = 0;
	token = strtok(input, " \n");

	while (token)
	{
		args[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}

	args[i] = NULL;
	return (i);
}


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

	buffer = ourhash_comment(buffer);

	return (buffer);
}
