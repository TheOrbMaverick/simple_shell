#include "shell.h"

/**
  * ourhash_comment - Removes content after the '#'
  * @input_string: A pointer to input string
  *
  * Return: The input string with the comment removed
  */

char *ourhash_comment(char *input_string)
{
	char *hash_position;

	/* Search for the first occurrence of the substring " #" */
	hash_position = strstr(input_string, " #");

	/* Check if " #" was found in the input string. */
	if (hash_position)
	{
		/* Replace the '#' character with a null terminator '\0' */
		*hash_position = '\0';
	}
	/* Return the modified or unmodified 'input_string' */
	return (input_string);
}
