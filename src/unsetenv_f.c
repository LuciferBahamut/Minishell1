/*
** EPITECH PROJECT, 2020
** unsetenv
** File description:
** minishell
*/

#include "my.h"

int unsetenv_f(mshel_s *ms)
{
    int space = check_space(ms->buffer);

    if (space > 1) {
        my_putstr(USETEER);
        return (SUCCESS);
    }
    else if (space == 0) {
        my_putstr(USETEER1);
        return (SUCCESS);
    }
    else
        return (SUCCESS);
}
