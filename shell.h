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
int forward_slash(char const *str);
char *file_path(char *file_name);
char *file_location(char *path, char *file_name);
void cmd_exe(char *user_input, char *argv[], char **env);
char *user_input_reader(void);
void user_prompt(void);
int tokenizer(char *user_input, char *args[]);

/* Built in Functions */
int builtin(char **args,
		int num_of_args, char *user_input,
		char **env);
void env_print(char **env);
void change_directory(char **args, int num_of_args);
void exit_handler(char *user_input, int exit_stat);
void exit_shell(char **args, char *user_input);
void ls_l_command();

/* Handle various symbols */
char *comments_handler(char *user_input);
#endif /* SHELL_H */
