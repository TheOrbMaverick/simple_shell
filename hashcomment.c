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

	hash_position = strstr(input_string, " #");

	if (hash_position)
	{
		*hash_position = '\0';
	}

	return (input_string);
}
