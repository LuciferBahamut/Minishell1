/*
** EPITECH PROJECT, 2020
** exe bin
** File description:
** minishell
*/

#include "my.h"

int check_path(char *envp, char *path)
{
    for (int i = 0; path[i] != '\0'; i++)
        if (path[i] != envp[i])
            return (ERROR);
        else
            if (path[i + 1] == '\0')
                return (SUCCESS);
}

char *my_getenv_path(char **envp, char *path)
{
    char *str;

    for (int i = 0; envp[i]; i++)
        if (check_path(envp[i], path) == SUCCESS) {
            str = malloc(my_strlen(envp[i]) + 1 * sizeof(char));
            for (int j = 5, k = 0; envp[i][j] != '\0'; j++, k++)
                str[k] = envp[i][j];
        }
    return (str);
}

void check_alias(mshel_s *ms)
{
    if (ms->arg[0][0] == 'l' && ms->arg[0][1] == 'l') {
        ms->arg[0] = "ls";
        ms->arg[1] = "-l";
    }
}

int check_exist(char **paths, int j)
{
    int nbr = 0;

    for (j = 0; paths[j]; j++)
        nbr++;
    for (j = 0; paths[j]; j++)
        if (access(paths[j], F_OK) != -1)
            break;
    if (nbr == j)
        return (ERROR);
    else
        return (j);
}

int exe_bin(mshel_s *ms)
{
    char *path = my_getenv_path(ms->envp, "PATH");
    char **paths = my_split_path(path);
    int j = 0;
    pid_t pid = 0;
    char *const *arg = ms->arg;

    check_alias(ms);
    for (int i = 0; paths[i]; i++)
        paths[i] = my_strcat(paths[i], ms->arg[0]);
    if ((j = check_exist(paths, j)) == ERROR) {
        display_error(ms->arg[0]);
        return (SUCCESS);
    }
    if ((pid = fork()) == 0)
        execve(paths[j], arg, ms->envp);
    wait(&pid);
    free(path);
    return (SUCCESS);
}
