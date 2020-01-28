/*
** EPITECH PROJECT, 2020
** dispatch_cmd.c
** File description:
** minishell 1
*/

#include "my.h"

void exit_f(void)
{
    my_putstr(EXIT);
    exit(SUCCESS);
}

static void display_error(char *str)
{
    my_putstr_error(str);
    my_putstr_error(": ");
    my_putstr_error(CMDNF);
}

void dispatch_cmd(mshel_s *ms)
{
    switch(ms->re) {
    case 0 : cd_f(ms);
        break;
    case 1 : return (SUCCESS);
        break;
    case 2 : return (SUCCESS);
        break;
    case 3 : return (SUCCESS);
        break;
    case 4 : exit_f();
        break;
    case 5 : display_error(ms->buffer);
        break;
    }
}
