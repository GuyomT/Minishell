/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myscreensaver-guillaume.terriere
** File description:
** my_str
*/

#include "minishell.h"

int my_strcmp(char const *s1, char const *s2, int len)
{
    int i = -1;

    while (s1[++i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]);
    if (len == 1)
    	return (s1[i] == '=' && s2[i] == '\0');
    return ((s1[i] == s2[i] || s1[i] == ' ' || s1[i] == '\t') && s2[i] == '\0');
}

char *my_strdup(char *str)
{
    int i;
    char *str2;

    if (str == NULL)
        return (NULL);
    if ((str2 = malloc(sizeof(char *) * (my_strlen(str) + 1))) == NULL)
        my_putstr("Error with malloc\n");
    i = -1;
    while (str[++i] != '\0')
        str2[i] = str[i];
    str2[i] = '\0';
    return (str2);
}

char *my_strcat(char *path, char *command, int cond)
{
    char *tab;
    int i;
    int j;
    if (path == NULL || command == NULL)
        return (NULL);
    if ((tab = malloc(sizeof(char) * (my_strlen(path) +
        my_strlen(command) + 2))) == NULL)
        my_putstrerror("Error with malloc\n");
    i = -1;
    while (path[++i] != '\0')
        tab[i] = path[i];
    if (cond == 1)
        tab[i++] = '/';
    if (cond == 2)
        tab[i++] = '=';
    j = 0;
    while (command[j] != '\0')
        tab[i++] = command[j++];
    tab[i] = '\0';
    return (tab);
}

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;
    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (i == n)
        dest[i] = '\0';
    return dest;
}

void my_free_tab(char **tab)
{
    int i = 0;

    if (tab != NULL) {
        while (tab[i])
            free(tab[i++]);
        free(tab);
    }
}