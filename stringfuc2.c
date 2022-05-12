#include "shell.h"


/**
  * strbrk - a function that breaks a long string in to arrauy of strings
  * @line: the string to be breakdown
  * @c: a chacter specifier where to break the string
  *
  * Return: returns the array of the words.
  */

char **strbrk(char *line, char c)
{
        int i = 0, j = 0;
        char **array, **tmp;

        if (!line || line[0] == '\0')
        {
                return (NULL);
        }
        array = malloc(sizeof(*array) * 128);
        if (array == NULL)
        {
                perror("Couldn't Allocate");
                return (NULL); }
        while (line[i] != '\0')
        {
                if (j > 124)
                {
                        tmp = realloc(array, sizeof(*array) * (i + 4));
                        if (tmp == NULL)
                        {
                                perror("Couldn't Reallocate");
                                return (NULL);
                        }
                        else
                        {
                                array = tmp;
                        }
                }
                if (line[i] == c)
                {
                        i++;
                        continue; }
                array[j] = stringer(line, i, array[j], c);
                if (array[j] == NULL)
                {
                        return (NULL); }
                i += strleng(array[j++]);
        }
        array[j] = NULL;
        return (array);
}


/**
  * stringer - a helper function to the string breaker
  * @line: a string pointer
  * @i: the index of the start of the string
  * @str: a string pointer to the location
  * @c: a character which specifys where to end the string
  * Return: returns a string pointer
  */

char *stringer(char *line, int i, char *str, char c)
{
        int k = 0;
        char *tmp;

        str = malloc(64);
        if (str == NULL)
        {
                perror("Couldn't Allocate");
                return (NULL);
        }
        while (line[i] != c && line[i] != '\0')
        {
                str[k] = line[i++];
                k++;
                if (k > 60)
                {
                        tmp = realloc(str, (k + 8));
                        if (!tmp)
                        {
                                perror("Error");
                                return (NULL);
                        }
                        else
                                str = tmp;
                }
        }

        str[k] = '\0';

        return (str);
}
