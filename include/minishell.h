/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-guillaume.terriere
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

#define BUFF_SIZE 512

typedef struct s_list
{
    char *data;
    struct s_list *next;
    struct s_list *prev;
}t_list;

void my_putchar(char);
int my_put_nbr(int);
void my_putstr(char *);
void my_putstrerror(char *);
int my_strlen(char const *);
int number_word(char *);
int my_strcmp(char const *s1, char const *s2, int len);
char *my_strdup(char *str);
int my_getnbr(char const *str);
char *my_strcat(char *path, char *command, int cond);
char **to_tab(char *buff, char *sep);
void my_free_tab(char **tab);
char **my_str_to_word_array(char *str, char *delims);
char *my_strncpy(char *dest, char *src, int n);
char *my_clean_str(char *str);

//init list
t_list *create_node(void);
t_list *init_listenv(char **env);
t_list *add_env(t_list *env, char *str, char *str2);
char **conv_list(t_list *env);

//search
int find_my_builtin(char **command, t_list *env);
char search_command(char **command, t_list *env);

//builtin
char my_exit(char **command, t_list *env);
char my_env(char **command, t_list *env);
char my_unsetenv(char **command, t_list *env);
char my_setenv(char **command, t_list *env);
char my_cd(char **command, t_list *env);

//execve
char my_execve(char **command, t_list *env, char *path);

//utils env
char *search_env(t_list *env, char *s);
void remove_env(t_list *env, char *command);
void display_env(t_list *env);
t_list *update_env(t_list *env, char *dir, char *str);

#endif /* !MINISHELL_H_ */

