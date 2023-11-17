#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

/* Execute Functions */
int startsWithForwardSlash(char const *str);
char *get_file_path(char *file_name);
char *get_file_loc(char *path, char *file_name);
void exe_cmd(char *input, char *argv[], char **env);
char *input_reader(void);
void user_prompt(void);
int tokenizer(char *input, char *args[]);

/* Built in Functions */
int builtin_cmd(char **args,
		int num_args, char *input,
		char **env);
void environs_print(char **env);
void cd_input(char **args, int num_args);
void _exit(char *input, int exit_status);
int exit_shell(char **args, char *input);

/* Handle various symbols */
char *handle_comment(char *input);
#endif /* SHELL_H */
