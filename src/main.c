/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac == 1)
        if (simple_cmd() == CEOF)
            return (SUCCESS);
    if (ac >= 3)
        return (ERROR);
    return (SUCCESS);
}
