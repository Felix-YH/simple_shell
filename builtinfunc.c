#include "shell.h"

/**
  * builtincom - a function to excute when unlisted command entered
  * @line: is a pointer to pointer of characters
  *
  * Return: returns an integer
  */

int builtincom(char **line)
{
        int status;
        pid_t waiter, child;

        child = fork();
        if (child == -1)
        {
                perror("Forking");
        }

        if (child == 0)
        {
                execve(line[0], line, NULL);
                if (errno != 0)
                {
                        return (errno);
                }
        }
        else
        {
                waiter = wait(&status);

                if (waiter == -1)
                {
                        perror("Waiting");
                }
        }

        free(line);
        return (0);
}
