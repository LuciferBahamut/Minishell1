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

int exe_bin(mshel_s *ms)
{
    char *path = my_getenv_path(ms->envp, "PATH");
    char **paths = my_split_path(path);
    int j = 0;
    pid_t pid = 0;

    for (int i = 0; paths[i]; i++)
        paths[i] = my_strcat(paths[i], ms->arg[0]);
    for (j = 0; paths[j]; j++)
        if (access(paths[j], F_OK) != -1)
            break;
    if ((pid = fork()) == 0)
        execve(paths[j], ms->arg[1], ms->envp);
    return (SUCCESS);
}
