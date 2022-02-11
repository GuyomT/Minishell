/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-guillaume.terriere
** File description:
** my_builtin
*/

#include "minishell.h"

char my_exit(char **command, t_list *env)
{
    t_list *tmp;
    int status = 0;

    if (command[1] != NULL) {
        status = my_getnbr(command[1]);
        status = status % 256;
    }
    if (env != NULL) {
        tmp = env->next;
        while (tmp != env) {
            free(tmp->data);
            tmp = tmp->next;
        }
        free(tmp);
    }
    my_putstr("\033[1;32mMinishell has stopped. \033[1;0m\n");
    exit(status);
    return (0);
}

char my_env(char **command, t_list *env)
{
    if (command[1] != NULL)
        my_putstr("env : too many arguments\n");
    else if (env != NULL)
        display_env(env);
    return (0);
}

char my_unsetenv(char **command, t_list *env)
{
    int i = 1;

    if (command[i] != NULL) {
        while (command[i] != NULL)
            remove_env(env, command[i++]);
    } else
        my_putstr("unsetenv: Too few arguments.\n");
    return (0);
}

char my_setenv(char **command, t_list *env)
{
    int i = -1;

    while (command[++i]);
    if (i > 3)
        my_putstr("setenv: Too many arguments\n");
    else if (command[1] != NULL) {
        remove_env(env, command[1]);
        env = add_env(env, command[2], command[1]);
    } else
        my_env(command, env);
    return (0);
}