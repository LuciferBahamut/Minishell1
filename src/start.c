/*
** EPITECH PROJECT, 2020
** start
** File description:
** project
*/

#include "my.h"

void fill_struct(mshel_s *ms, char **envp)
{
    ms->buffer = malloc((100 + 1) * sizeof(char));
    ms->envp = envp;
}

int start(int ac, char **av, char **envp)
{
    mshel_s *ms = malloc(sizeof(char *) * 2 + sizeof(char) + sizeof(int));

    if (ac != 1) {
        free(ms);
        exit(ERROR);}
    fill_struct(ms, envp);
    if (simple_cmd(ms) == CEOF)
        exit(SUCCESS);
    free(ms);
    return (SUCCESS);
}
