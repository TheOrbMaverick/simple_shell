#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/wait.h>

void display_prompt(void);
char *read_input(void);
void execute_command(char *command);
void my_printf(const char *format, ...);
char *custom_strtok(char *str, const char *delim);

#endif
