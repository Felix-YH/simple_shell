#include "shell.h"

/**
 * _getchar - a function that reads a character from the standard input
 *
 * Return: returns the read character
 */

char _getchar(void)
{
        char *buf;
        char c;
        int i = 0;

        buf = malloc(2);

        if (!buf)
                return (-1);

        fflush(stdout);

        i = read(1, buf, 1);
        if (i == -1)
        {
                perror("Reading Char");
                return (-1);
        }
        else if (i == 0)
        {
                write(1, "\n", 2);
                fflush(stdout);
                exit(1);
        }

        c = *buf;

        return (c);
}
