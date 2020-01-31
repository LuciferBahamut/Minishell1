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
    ms->status = 0;
}

int start(int ac, char **av, char **envp)
{
    mshel_s *ms = malloc(sizeof(mshel_s));

    if (ac != 1) {
        free(ms);
        exit(ERROR);}
    fill_struct(ms, envp);
    if (simple_cmd(ms) == CEOF)
        exit(SUCCESS);
    free(ms);
    return (SUCCESS);
}
