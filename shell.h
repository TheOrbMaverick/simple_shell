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

/* Function Prototypes*/
void user_prompt(void);
void our_printf(const char *format, ...);
void read_input(char *user_input, size_t size);
void execute_input(char *user_input);
char *ourhash_comment(char *input_string);
char *simple_getline(FILE *input_stream);
void simple_cd(char **args, int nof_args);
void simple_env(char **henv);

#endif
