/*
** EPITECH PROJECT, 2020
** cd
** File description:
** minishell1
*/

#include "my.h"

int cd_f(mshel_s *ms)
{
    int space = check_space(ms->buffer);

    if (space == 0)
        return (SUCCESS);
    if (space >= 2) {
        my_putstr(CDER);
        return (SUCCESS);
    }
    else
        if (chdir(ms->arg[1]) == -1) {
            perror(ms->arg[1]);
            return (SUCCESS);
        }
}
