#include "shell.h"

/**
  * just_exit - The exit functionality
  * @val_put: value
  * @my_status: Exit status
  */

void just_exit(char *val_put, int my_status)
{
	free(val_put);
	exit(my_status);
}

/**
  * hell_exit - Function for  exit status
  * @args: Arguments
  * @val_put: status checker
  *
  * Return: Status of exit, 1 if otherwise
  */

int hell_exit(char **args, char *val_put)
{
	char *str_put;
	int my_status, k;

	if (args[1] != NULL)
	{
		my_status = 0;
		str_put = args[1];

		for (k = 0; str_put[k] != '\0'; k++)
		{
			if (str_put[k] < '0' || str_put[k] > '9')
			{
				just_exit(val_put, 2);
				return (1);
			}
			my_status = my_status * 10 + (str_put[k] - '0');
		}
		just_exit(val_put, my_status);
	}
	else
	{
		just_exit(val_put, 132);
	}
	return (1);
}
