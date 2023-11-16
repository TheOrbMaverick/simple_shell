#ifndef SHELL_H
#define SHELL_H

/* Include necessary header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>

/* Function Prototypes*/
void user_prompt(void);
char *read_input(void);
void execute_input(char *user_input, char *argv[], char **env);
void my_printf(const char *format, ...);

#endif

