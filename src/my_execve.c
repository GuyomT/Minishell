/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-guillaume.terriere
** File description:
** my_execve
*/

#include "minishell.h"

void error_execve(char *error, char **command, char** tabenv)
{
    my_putstr(command[0]);
    if (my_strlen(error) == 0)
        my_putstr(": Command not found.");
    else
        my_putstr(": Permission denied.");
    my_putstr("\n");
    my_free_tab(command);
    my_free_tab(tabenv);
}

char test_filename(char opt1, char opt2, char **command)
{
    if (opt1 != ' ') {
        if (command[0][0] == opt1 && command[0][1] == opt2 &&
            (access(command[0], F_OK) != -1))
            return 0;
    }
    else if (opt1 == ' ')
        if (command[0][0] == opt2 && (access(command[0], F_OK) != -1))
            return 0;
    return 1;
}

char *execve_recursive(char **path, char **command, char **tabenv, int i)
{
    char *filename = NULL;

    if (!test_filename('.', '/', command)) {
        if (((filename = command[0]) && (access(command[0], R_OK | X_OK) == -1))
            || (execve(filename, command, tabenv) == -1))
            return ("Permissions denied.");
    }
    else if (command[0][0] != '/')
        filename = my_strcat(path[i++], command[0], 1);
    else if (!test_filename(' ', '/', command))
        if (((filename = command[0]) && (access(command[0], R_OK | X_OK) == -1))
            || (execve(filename, command, tabenv) == -1))
            return ("Permission denied.");
    if (filename != NULL) {
        execve(filename, command, tabenv);
        execve_recursive(path, command, tabenv, i);
    } else
        return NULL;
    return 0;
}

void my_print_err_status(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 11)
            if (WCOREDUMP(status))
                my_putstrerror("Segmentation fault (core dumped)\n");
            else
                my_putstrerror("Segmentation fault\n");
        else if (WTERMSIG(status) == 8)
            my_putstrerror("Floating Point Exception\n");
    }
}

char my_execve(char **command, t_list *env, char *path)
{
    char **tabenv = NULL;
    int status;
    pid_t pid;
    char *error = NULL;
    int i;
    char **path_tab = my_str_to_word_array(path, ":");
    pid = fork();
    if (pid == -1)
        my_putstrerror("Error with pid\n");
    else if (pid == 0) {
        i = 0;
        tabenv = conv_list(env);
        error = execve_recursive(path_tab, command, tabenv, i);
        my_free_tab(path_tab);
        error_execve(error, command, tabenv);
        exit(1);
    }pid = waitpid(pid, &status, '\0');
    my_print_err_status(status);
    my_free_tab(path_tab);
    return 0;
}
