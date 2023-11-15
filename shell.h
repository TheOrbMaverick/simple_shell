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
void our_printf(const char *format, ...);
char *read_input(void);
void execute_input(char *user_input, char *argv[], char **env);
char *ourhash_comment(char *input_string);
char *simple_getline(FILE *input_stream);
void simple_cd(char **args, int nof_args);
void simple_env(char **env);
int hell_exit(char **args, char *val_put);
int func_builtin_commands(char **args, int nof_args, char *val_put, char **env);
char *find_file(const char *directories, const char *filename);
char *f_path(const char *name);
int forward_slash(const char *str);
int tokenizer(char *input, char *args[]);


#endif
