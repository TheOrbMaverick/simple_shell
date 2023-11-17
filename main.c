#include "shell.h"

/**
 * main - Entry point for the shell program.
 *
 * Return: Always returns 0.
 */

int main(void)
{
    int pipe_fd[2];
    pid_t child_pid;
    char *const cmd_ls[] = {"ls", NULL};
    char *const cmd_wc[] = {"wc", "-l", NULL};

    /* Create a pipe */
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    /* Fork a child process */
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        /* Child process */
        close(pipe_fd[0]);  /* Close the read end of the pipe */
        dup2(pipe_fd[1], STDOUT_FILENO);  /* Redirect stdout to the pipe */

        /* Execute the first command (e.g., ls) */
        execve("/bin/ls", cmd_ls, NULL);

        /* If execve fails */
        perror("execve");
        exit(EXIT_FAILURE);
    } else {
        /* Parent process */
        close(pipe_fd[1]);  /* Close the write end of the pipe */
        dup2(pipe_fd[0], STDIN_FILENO);  /* Redirect stdin to the pipe */

        /* Execute the second command (e.g., wc) */
        execve("/usr/bin/wc", cmd_wc, NULL);

        /* If execve fails */
        perror("execve");
        exit(EXIT_FAILURE);
    }

    return 0;
}
