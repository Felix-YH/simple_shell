#include "shell.h"

/**
* exitor - a function to exit from the program
* @line: an array of command and arguments
*
* Return: no return
*/

int exitor(char *line[])
{
int i = 0;
if (line[1] == NULL)
{
exit(EXIT_SUCCESS); }
else if (atoi(line[1]) > 0)
{
i = atoi(line[1]); }
free(line);
exit(i);
}

/**
* changedire - a function to change a directory
* @line: an array of commands and arguments
*
* Return: returns 0 in success and -1 if it fails
*/
