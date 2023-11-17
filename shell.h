#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>

void display_prompt(void);
char *read_input(void);
void execute_command(const char *command, char *argv0);
void my_printf(const char *format, ...);

#endif
