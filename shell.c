#include "shell.h"

void display_prompt(void) {
	printf("#cisfun$ ");
}

char *read_input(void) {
	char *buffer = NULL;
	size_t bufsize = 0;

	if (getline(&buffer, &bufsize, stdin) == -1) {
		/* Handle Ctrl+D or other exit conditions */
		free(buffer);
		return NULL;
	}

	/* Remove newline character */
	buffer[strcspn(buffer, "\n")] = '\0';

	return buffer;
}

void execute_command(const char *command) {
	/* Implement command execution logic here */
	/* You may need to parse the command and use execvp or other functions */
	printf("Executing: %s\n", command);
}
