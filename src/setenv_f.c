/*
** EPITECH PROJECT, 2020
** setenv
** File description:
** minishell
*/

#include "my.h"

int setenv_f(mshel_s *ms)
{
    int space = check_space(ms->buffer);

    if (space > 3) {
        my_putstr_error(SETEER);
        return (SUCCESS);
    }
}
