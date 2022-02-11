/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-guillaume.terriere
** File description:
** main
*/

#include "minishell.h"

void print_prompt(void)
{
    my_putstr("\033[1;31m");
    my_putstr("$> ");
    my_putstr("\033[1;0m");
}

void my_prompt(t_list *env, int nb)
{
    char *user;
    char *pwd;

    user = search_env(env, "USER");
    pwd = search_env(env, "PWD");

    if (nb == 1)
        my_putstr("\033[1;32mMinishell 1 by Guyom working... \033[1;0m \n");
    if (user != NULL || pwd != NULL) {
        my_putstr("\033[1;31m");
        my_putstr("[");
        if (user)
            my_putstr(user);
        if (pwd) {
            my_putstr("@");
            my_putstr("\033[1;36m");
            my_putstr(pwd);
        }
        my_putstr("\033[1;31m");
        my_putstr("]");
    }
    print_prompt();
}

char minishell(char *buff, t_list *env)
{
    char *command = my_clean_str(buff);
    char **tab = my_str_to_word_array(command, " \t");
    search_command(tab, env);
    my_free_tab(tab);
    free(command);
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    char buff[BUFF_SIZE + 1];
    t_list *env;
    int fd = 0;

    env = init_listenv(envp);
    (void)argc;
    (void)argv;
    my_prompt(env, 1);
    while ((fd = read(0, buff, BUFF_SIZE)) > 0) {
        if (fd == BUFF_SIZE) {
            my_putstr("Commands too big !\n");
            my_putstr("\033[1;32mMinishell 1 stopped... \033[1;0m \n");
            exit(0);
        }
        buff[fd - 1] = '\0';
        minishell(buff, env);
        my_prompt(env, 2);
    }
    close(fd);
    my_putstr("\033[1;32mMinishell 1 stopped... \033[1;0m \n");
    return (0);
}