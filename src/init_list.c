/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-guillaume.terriere
** File description:
** init_list
*/

#include "minishell.h"

t_list *create_node(void)
{
    t_list *node;

    if ((node = malloc(sizeof(t_list))) == NULL)
        my_putstrerror("Error malloc.\n");
    node->next = node;
    node->prev = node;
    return (node);
}

t_list *init_listenv(char **env)
{
    t_list *env_tmp;
    t_list *tmp;
    int i = 0;
    int j = 0;

    env_tmp = create_node();
    while (env[i] != NULL) {
        j = -1;
        tmp = create_node();
        if ((tmp->data = malloc(my_strlen(env[i]) + 1)) == NULL)
            my_putstrerror("Error with malloc.\n");
        while (env[i][++j] != '\0')
            tmp->data[j] = env[i][j];
        tmp->data[j] = '\0';
        tmp->prev = env_tmp->prev;
        tmp->next = env_tmp;
        env_tmp->prev->next = tmp;
        env_tmp->prev = tmp;
        i++;
    }
    return (env_tmp);
}

t_list *add_env(t_list *env, char *str, char *str2)
{
    t_list *tmp;
    int i = 0;
    int z = 0;

    tmp = create_node();
    if ((tmp->data = malloc(my_strlen(str) + my_strlen(str2) + 2)) == NULL)
        my_putstrerror("Problem with malloc\n");
    while (str2 && str2[i] != '\0')
        tmp->data[z++] = str2[i++];
    i = 0;
    tmp->data[z++] = '=';
    while (str && str[i] != '\0')
        tmp->data[z++] = str[i++];
    tmp->data[z] = '\0';
    tmp->prev = env->prev;
    tmp->next = env;
    env->prev->next = tmp;
    env->prev = tmp;
    return (env);
}

int count_list(t_list *tmp, t_list *env)
{
    int count = 0;

    while (tmp != env) {
        ++count;
        tmp = tmp->next;
    }
    return (count);
}

char **conv_list(t_list *env)
{
    t_list *tmp;
    char **tab;
    int i;

    if (env->prev->data == NULL)
        return (NULL);
    tmp = env->next;
    if ((tab = malloc(sizeof(char *) * (count_list(tmp, env) + 1))) == NULL)
        my_putstrerror("Error with malloc\n");
    i = -1;
    while (tmp != env) {
        tab[++i] = my_strdup(tmp->data);
        tmp = tmp->next;
    }
    tab[i] = '\0';
    return (tab);
}