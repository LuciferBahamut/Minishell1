/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** minishell
*/

#ifndef MY_H_
#define MY_H_

#define SUCCESS 0
#define ERROR 84
#define CEOF 9

#define RES "\e[0;0m"
#define RED "\e[3;1;5;31m"
#define CYAN "\e[1;36m"
#define GR "\e[1;32m"
#define BLUE "\e[1;34m"
#define YE "\e[1;33m"
#define CMD BLUE"₪"YE"["CYAN"卐"RED"CMD"RES CYAN"卐"YE"]"BLUE"₪ "GR"→ "RES

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>

int simple_cmd(void);
void my_putchar(char c);
int my_putstr(char const *str);

#endif
