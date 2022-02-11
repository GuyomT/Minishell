/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myradar-guillaume.terriere
** File description:
** my_getnbr
*/

#include "minishell.h"

int my_getnbr(char const *str)
{
    int var = 0;
    int inv = 1;
    int i = 0;

    if (str == NULL)
        return (0);
    while ((*str < '0' || *str > '9') && *str != 0) {
        str++;
        i++;
    }
    if (i > 0 && *(str - 1) == '-')
        inv = -1;
    while (*str != 0 && *str >= '0' && *str <= '9') {
        var = var * 10;
        var = var + *str - 48;
        str++;
    }
    var = var * inv;
    return (var);
}