#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

extern int errno;
/**
* struct selectfunction - a struct array of functions
* @command: a pointer to the caharacter of the command string
* @funcptr: a pointer to a function
*/
typedef struct selectfunction
{
	char *command;
	int (*funcptr)(char **line);
} selecte;
void sigintHandler(int sig_num __attribute__((unused)));
void printprompt(int i);
int getstr(char *str);
int (*getfunc(char *str))(char **line);
int _getline(char **line, size_t *len);
char _getchar(void);
void strmix(char *src, char *dest);
int strleng(char *s);
void strcopy(char *src, char *dest);
int echorr(char *line[]);
int strcomp(char *str, char *equ);
int builtincom(char **line);
int shellprocessor(char **line, char **argv);
char **strbrk(char *line, char c);
char *stringer(char *line, int i, char *str, char c);

#endif /* SIMPLE_SHELLY */
