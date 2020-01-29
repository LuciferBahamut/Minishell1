/*
** EPITECH PROJECT, 2020
** simple_cmd
** File description:
** minishell
*/

#include "my.h"

int simple_cmd(mshel_s *ms)
{
    char *buffer = ms->buffer;
    size_t size = 100;

    while (1) {
        my_putstr(CMD);
        if (getline(&buffer, &size, stdin) == EOF) {
            my_putstr(EXIT);
            return (CEOF);
        }
        break;
    }
    ms->buffer = clear_space(buffer);
    for (int i = 0; ms->buffer[i] != '\0'; i++)
        if (ms->buffer[i] == '\n')
            ms->buffer[i] = '\0';
    ms->arg = my_split(ms->buffer);
    ms->re = check_command(ms->arg[0]);
    dispatch_cmd(ms);
    simple_cmd(ms);
    return (SUCCESS);
}
