#include "shell.h"

/**
 * tokenizer - Tokenize user input into an array of strings.
 * @input: User input to tokenize.
 * @args: An array to store the tokens.
 *
 * Returns: The number of tokens.
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
    return i;
}

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

    buffer = ourhash_comment(buffer);

    return buffer;
}
