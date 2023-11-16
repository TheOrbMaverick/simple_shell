#include "shell.h"

/*
 * find_file - Search for a file in specified directories.
 * @directories: Colon-separated list of directories to search in.
 * @filename: The name of the file to find.
 *
 * This function searches for the specified file in the given directories.
 * If the file is found and is executable, the full path is returned.
 * If not found or not executable, NULL is returned.
 *
 * Returns: On success, the full path of the file. On failure, NULL.
 */
char *find_file(const char *directories, const char *filename)
{
	/* Duplicate the directories string to avoid modifying the original */
	char *dir_copy = strdup(directories);
	/* Tokenize the directories using ":" as the delimiter */
	char *token = strtok(dir_copy, ":");
	/* Structure to hold file information */
	struct stat file_stat;

	/* Iterate through each directory token */
	while (token)
	{
		/* Allocate memory for the full path */
		char *path = malloc(strlen(token) + strlen(filename) + 2);

		if (!path)
		{
			/* Handle malloc failure */
			perror("Error: malloc failed");
			exit(EXIT_FAILURE);
		}

		/* Construct the full path by concatenating directory and filename */
		snprintf(path, strlen(token) + strlen(filename) + 2, "%s/%s", token, filename);

		/* Check if the file at the constructed path is executable */
		if (stat(path, &file_stat) == 0 && access(path, X_OK) == 0)
		{
			/* Free the duplicated directory string */
			free(dir_copy);
			/* Return the full path if the file is executable */
			return path;
		}

		/* Free the allocated path memory */
		free(path);
		/* Move to the next directory token */
		token = strtok(NULL, ":");
	}

	/* Free the duplicated directory string */
	free(dir_copy);
	/* Return NULL if the file is not found in any directory */
	return (NULL);
}
