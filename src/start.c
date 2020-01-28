/*
** EPITECH PROJECT, 2020
** start
** File description:
** project
*/

#include "my.h"

void multi_free(mshel_s *ms)
{
    free(ms->buffer);
    free(ms->arg);
    free(ms);
}

void fill_struct(mshel_s *ms)
{
    ms->buffer = malloc((100 + 1) * sizeof(char));
}

int start(int ac, char **av, char **envp)
{
    mshel_s *ms = malloc(sizeof(char *) * 1 + sizeof(char) + sizeof(int));

    fill_struct(ms);
    if (ac == 1)
        if (simple_cmd(ms) == CEOF)
            exit(SUCCESS);
    multi_free(ms);
    return (SUCCESS);
}
