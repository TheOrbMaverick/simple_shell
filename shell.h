#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_prompt(void);
char *read_input(void);
void execute_command(const char *command);
void my_printf(const char *format, ...);

#endif
