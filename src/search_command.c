/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-guillaume.terriere
** File description:
** search_command
*/

#include "minishell.h"

char *is_there_a_path(char *path)
{
    if (path == NULL)
        return ("/bin:/sbin:/usr/bin:/usr/sbincl");
    return (path);
}

int find_my_builtin(char **command, t_list *env)
{
    char (*pf_redir[5])(char **, t_list *);
    char **builtin;
    int i = -1;

    if ((builtin = malloc(sizeof(char *) * 5)) == NULL)
        my_putstrerror("Error malloc.\n");
    builtin[0] = "exit";
    builtin[1] = "cd";
    builtin[2] = "env";
    builtin[3] = "unsetenv";
    builtin[4] = "setenv";
    pf_redir[0] = my_exit;
    pf_redir[1] = my_cd;
    pf_redir[2] = my_env;
    pf_redir[3] = my_unsetenv;
    pf_redir[4] = my_setenv;
    while (++i < 5 && !my_strcmp(command[0], builtin[i], 0));
    free(builtin);
    if (i == 5)
        return (1);
    return (pf_redir[i](command, env));

}

char search_command(char **command, t_list *env)
{
    if (command[0] == NULL || command == NULL)
        return (0);
    if ((find_my_builtin(command, env)) == 1)
        my_execve(command, env, is_there_a_path(search_env(env, "PATH")));
    return (0);
}