#include "shell.h"
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/**
  * env_print - Prints the environment variables
  * @env: Arguments
  */

void env_print(char **env)
{
	while (*env != NULL)
	{
		write(1, *env, strlen(*env));
		write(1, "\n", 1);
		env++;
	}
}


/**
  * exit_handler - Handles the exit functionality
  * @user_input: user_input value to handle
  * @exit_stat: Exit status of the code
  */

void exit_handler(char *user_input, int exit_stat)
{
	free(user_input);
	exit(exit_stat);
}

/**
  * exit_shell - Handles the exit status
  * @args: Arguments to the function
  * @user_input: Checks the status of exit
  *
  * Return: Status of exit, 1 if otherwise
  */

void exit_shell(char **args, char *user_input)
{
	(void)args;
	free(user_input);
	exit(0);
}

/**
  * change_directory - Handles the cd functionality
  * @args: Array of commands
  * @num_of_args: Argument count
  */

void change_directory(char **args, int num_of_args)
{
	const char *home_directory, *pre_directory;

	home_directory = getenv("HOME");
	pre_directory = getenv("OLDPWD");

	if (num_of_args == 1 || strcmp(args[1], "~") == 0)
	{
		if (!home_directory)
		{
			perror("Home environment not set");
			return;
		}
		if (chdir(home_directory) != 0)
			perror("cd");
	}
	else if (num_of_args == 2 && strcmp(args[1], "-") == 0)
	{
		if (!pre_directory)
		{
			perror("OLDPWD environment not set");
			return;
		}
		if (chdir(pre_directory) != 0)
			perror("cd");
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
}

/**
 * Print detailed information about each file in
 * the current directory.
 * Prints permissions, number of hard links, and file name.
 */

void ls_l_command() {
    struct stat file_stat;
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &file_stat) < 0) {
            perror("Error");
            exit(EXIT_FAILURE);
        }

        printf((S_ISDIR(file_stat.st_mode)) ? "d" : "-");
        printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
        printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
        printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
        printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
        printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
        printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
        printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
        printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
        printf((file_stat.st_mode & S_IXOTH) ? "x " : "- ");
        printf("%ld ", file_stat.st_nlink);
        printf("%s ", entry->d_name);
        printf("\n");
    }

    closedir(dir);
}
