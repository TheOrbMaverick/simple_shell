#include "shell.h"

/**
 * main - Simple UNIX command line interpreter.
 *
 * Return: Always returns 0.
 */

#define MAX_COMMAND_LENGTH 100
int main(void)
{
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    size_t len;

    while (1)
    {
        /* Display the prompt */
        printf("$ ");

        /* Read the command from the user */
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            /* Handle Ctrl+D (EOF) */
            printf("\n");
            break;
        }

        /* Remove the newline character */
        len = strlen(command);
        if (len > 0 && command[len - 1] == '\n')
        {
            command[len - 1] = '\0';
        }

        /* Fork a new process */
        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            /* Child process */
            /* Execute the command */
            if (execve(command, NULL, NULL) == -1)
            {
                /* Handle error */
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* Parent process */
            /* Wait for the child to finish */
            int status;
            waitpid(pid, &status, 0);

            /* Check if the child process exited successfully */
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
            {
                printf("Command executed successfully.\n");
            }
            else
            {
                printf("Error executing the command.\n");
            }
        }
    }

    printf("Exiting shell.\n");
    return (0);
}