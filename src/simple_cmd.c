/*
** EPITECH PROJECT, 2020
** simple_cmd
** File description:
** minishell
*/

#include "my.h"

int simple_cmd(void)
{
    size_t size = 100;
    char *buffer = malloc((size + 1) * sizeof(char));

    while (1) {
        my_putstr(CMD);
        if (getline(&buffer, &size, stdin) == EOF) {
            my_putchar('\n');
            return (CEOF);
        }
        break;
    }
    simple_cmd();
    free(buffer);
    return (SUCCESS);
}
