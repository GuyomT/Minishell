/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-guillaume.terriere
** File description:
** my_str_to_tab
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "minishell.h"

int my_get_char_in(char const *str, char c)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] == c)
            return 1;
    return 0;
}

static int count_words(char *str, char *delims)
{
    int words = 0;

    while (*str) {
        while (*str && my_get_char_in(delims, *str))
            str++;
        words += ((*str) != 0);
        while (*str && !my_get_char_in(delims, *str))
            str++;
    }
    return words;
}

char **my_str_to_word_array(char *str, char *delims)
{
    int count = count_words(str, delims);
    char **array = malloc(sizeof(char *) * (count + 1));
    int start;
    int i = 0;
    int w = 0;

    while (str[i]) {
        while (str[i] && my_get_char_in(delims, str[i]))
            i++;
        start = i;
        while (str[i] && !my_get_char_in(delims, str[i]))
            i++;
        array[w] = malloc(sizeof(char) * (i - start + 1));
        my_strncpy(array[w], str + start, (i - start));
        array[w++][i - start] = 0;
    }
    array[w] = NULL;
    return array;
}