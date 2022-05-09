#include "shell.h"
  2
  3 /**
  4  * copyarray - a function to copy string array to another string array variable
  5  * @line: a string array to be copied
  6  * Return: returns the copied array
  7  */
  8
  9 char **copyarray(char **line)
 10 {
 11         char **array;
 12         int i = 1;
 13
 14         array = malloc(64);
 15         if (!array)
 16                 return (NULL);
 17
 18         while (line[i] != NULL)
 19         {
 20                 array[(i - 1)] = malloc(32);
 21                 if (!array[(i - 1)])
 22                         return (NULL);
 23
 24                 strcopy(line[i], array[(i - 1)]);
 25                 i++;
 26         }
 27
 28         return (array);
 29 }
 30
 31 /**
 32  * sigintHandler - a function to handle the ctrl-c signal
 33  * @sig_num: an integer signal indicator
 34  *
 35  * Return: void function
 36  */
 37
 38 void sigintHandler(int sig_num __attribute__((unused)))
 39 {
 40         signal(SIGINT, sigintHandler);
 41         write(1, "\n", 2);
 42         printprompt(0);
 43         fflush(stdout);
 44 }

/**
 48  * main - a the main function of the shell
 49  * @argc: the number of arguments given
 50  * @argv: an array of given argument strings
 51  *
 52  * Return: returns an integer
 53  */
 54
 55 int main(int argc __attribute__((unused)), char **argv)
 56 {
 57         char *line;
 58
 59         line = malloc(256);
 60         if (!line)
 61         {
 62                 perror("Allocation");
 63                 exit(1);
 64         }
 65
 66         if (!isatty(STDIN_FILENO))
 67         {
 68                 if (getstr(line) == (-1))
 69                 {
 70                         write(1, "\n", 2);
 71                         exit(1);
 72                 }
 73                 if (shellprocessor(strbrk(line, ' '), argv) == -1)
 74                 {
 75                         perror("Error");
 76                 }
 77
 78                 exit(0);
 79         }
 80
 81         do {
 82                 printprompt(0);
 83                 if (getstr(line) == (-1))
 84                 {
 85                         write(1, "\n", 2);
 86                         exit(0);
 87                 }
 88
 89                 if ((shellprocessor(strbrk(line, ' '), argv)) == -1)
 90                 {
 91                         perror("Error");
 92                 }
 93         } while (1);
 94
 95         return (0);
 96 }
