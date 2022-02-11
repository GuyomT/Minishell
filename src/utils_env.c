/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-guillaume.terriere
** File description:
** utils_env
*/

#include"minishell.h"

char *search_env(t_list *env, char *s)
{
    t_list *tmp;
    int i = 0;

    if (env->prev->data == NULL)
        return (NULL);
    tmp = env->next;
    while (tmp != env) {
        i = 0;
        while (s[i] == tmp->data[i]) {
            i++;
            if (tmp->data[i] == '=' && (my_strlen(s) == i))
                return (&tmp->data[i + 1]);
        }
        tmp = tmp->next;
    }
    return (NULL);
}

void remove_env(t_list *env, char *command)
{
    t_list *tmp;

    tmp = env->next;
    while (tmp != env && !my_strcmp(tmp->data, command, 1))
        tmp = tmp->next;
    if (tmp != env) {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp->data);
        free(tmp);
    }
}

void display_env(t_list *env)
{
    t_list *tmp;

    tmp = env->next;
    while (tmp != env) {
        my_putstr(tmp->data);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

t_list *update_env(t_list *env, char *dir, char *str)
{
    t_list *tmp;
    int i;
    int z;

    z = 0;
    tmp = env->next;
    while (tmp != env) {
        i = 0;
        while (tmp->data[i] == str[i])
            ++i;
        if (tmp->data[i] == '=') {
            i = 0;
            if ((tmp->data = malloc(sizeof(char) * my_strlen(dir) + 2)) == NULL)
                my_putstrerror("Error with malloc\n");
            while (dir[z] != '\0')
                tmp->data[i++] = dir[z++];
            tmp->data[i] = '\0';
        }
        tmp = tmp->next;
    }
    return (tmp);
}