/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-guillaume.terriere
** File description:
** my_clean_str
*/

#include "minishell.h"

int end_str(char *str)
{
    int i = my_strlen(str) - 1;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i--;
    }
    return i;
}

char *my_clean_str(char *str)
{
    int i = 0;
    int j = 0;
    int end = end_str(str);
    char *tmp = malloc(sizeof(char) * 4096);

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (i <= end) {
        if (str[i] != ' ' || str[i + 1] == ' ' ||
        str[i]!= '\t') {
            tmp[j] = str[i];
            i++;
            j++;
        }
        while ((str[i] == ' ' && str[i + 1] == ' ')
            || str[i] == '\t')
            i++;
    }
    tmp[j] = '\0';
    return tmp;
}