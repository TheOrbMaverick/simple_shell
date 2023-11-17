#include "shell.h"

/**
  * comments_handler - Handles the '#' in the user_input
  * @user_input: user_input value
  *
  * Return: The stripped down user_input
  */

char *comments_handler(char *user_input)
{
	char *comment;

	comment = strstr(user_input, " #");

	if (comment)
	{
		*comment = '\0';
	}

	return (user_input);
}
