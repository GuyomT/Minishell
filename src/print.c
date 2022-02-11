/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-pushswap-guillaume.terriere
** File description:
** print
*/

#include <unistd.h>
#include <minishell.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] && str[i] != '\0')
        i++;
    return (i);
}

void my_putstr(char *str)
{
    write(1, &str[0], my_strlen(str));
}

void my_putstrerror(char *str)
{
    write(2, &str[0], my_strlen(str));
}

int my_put_nbr(int nb)
{
    int d;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    d = (nb % 10 + 48);
    my_putchar(d);
    return (0);
}