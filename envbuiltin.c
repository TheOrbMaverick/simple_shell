#include "shell.h"

/**
  * simple_env - A function that prints environment variables
  * henv: The arguments
  */

void simple_env(char **henv)
{
	while (*henv != NULL)
	{
		write(1, *henv, strlen(*henv));
		write(1, "\n", 1);
		henv++;
	}
}
