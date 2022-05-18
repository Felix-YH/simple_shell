#include "shell.h"

/**
 * getstr - function to read a string from  the cli
 * @str: a string pointer
 *
 * Return: return 1 in success and -1 in failure
 */

int getstr(char *str)
{
	char **line;
	size_t siz = 0;

	signal(SIGINT, sigintHandler);
	line = malloc(24);
	if (!line)
	{
		return (-1);
	}

	if ((getline(line, &siz, stdin)) == -1)
	{
		return (-1);
	}

	line[0][siz] = '\0';

	strcopy(line[0], str);

	if (line[0][siz - 2] == '\\')
	{
		do {
			str[strleng(str) - 1] = ' ';
			siz = 0;
                        printprompt(1);

                        if ((getline(line, &siz, stdin)) == -1)
                        {
                                return (-1);
                        }
                        line[0][siz] = '\0';

                        strmix(line[0], str);
                } while (line[0][siz - 2] == '\\');
        }

        free(line);
        return (1);
}

/**
 * strcopy - a function to copy to strings
 * @src: the string to be copied
 * @dest: the destination of the copied string
 *
 * Return: returns nothing (void)
 */
        void strcopy(char *src, char *dest)
{
        int i = 0;
        int j = 0;
        if (!dest)
        {
                j = 0;
        }
        while (src[i] != '\0' && src[i] != '\n')
        {
                dest[j++] = src[i++];
        }
        dest[j] = '\0';
}


/**
* strmix - a function to copy to strings and concatenate if
*        the destination have a string already.
* @src: the string to be copied
* @dest: the destination of the copied string
*
* Return: returns nothing (void)
*/
void strmix(char *src, char *dest)
{
        int i = 0;
        int j;
        if (!dest)
        {
                j = 0;
        }
        else
        {
                j = strleng(dest);
        }
        while (src[i] != '\0' && src[i] != '\n')
        {
                dest[j++] = src[i++];
        }
        dest[j] = '\0';
}


/**
* strleng - measures a length of a string
* @s: a string location pointer
*
* Return: returns length
*/

int strleng(char *s)
{
        int len = 0;
        while (s[len] != '\0')
        {
                len++;
        }
        return (len);
}


/**
* strcomp - a function to compare two strings
* @str: the first string to compare
* @equ: the secodn string to comapre too
*
* Return: returns an integer indicater of the boolean
*/
int strcomp(char *str, char *equ)
{
        int i = 0;
        int result = 0;
        if (str == NULL || equ == NULL)
        {
                return (0);
        }
        while (equ[i] != '\0' || str[i] != '\0')
        {
                if (str[i] == equ[i])
                {
                        result = 1;
                }
                else
                {
                        result = 0;
                }
                i++;
        }
        return (result);
}
