#include "shell.h"

/**
  * main - Wait program
  * @argc: Argumnt count
  * @argv: Array of arguments
  * @env: Environment variable
  *
  * Return: O Always succes
  */

int main(int argc, char *argv[], char **env)
{
	char *temp_input_storage;
	(void)argc;

	while (1)
	{
		user_prompt();
		temp_input_storage = user_input_reader();
		cmd_exe(temp_input_storage, argv, env);
		free(temp_input_storage);
	}

	return (0);
}
