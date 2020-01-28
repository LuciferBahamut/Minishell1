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
#define CMD BLUE"₪"YE"["CYAN"♜"RED"CMD"RES CYAN"♜"YE"]"BLUE"₪ "GR"→ "RES

#define EXIT "exit\n"

#define CMDNF "Command not found.\n"
#define CDER "cd: Too many arguments.\n"

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
#include <string.h>

typedef struct mshel
{
    int re;
    char *buffer;
    char **arg;
    char **envp;
} mshel_s;

int start(int ac, char **av, char **envp);
int simple_cmd(mshel_s *ms);
void my_putchar(char c);
void my_putchar_error(char c);
int my_putstr(char const *str);
int my_putstr_error(char const *str);
void dispatch_cmd(mshel_s *ms);
int check_command(char *arg);
int my_strlen(char const *str);
char **my_split(char *src);
int cd_f(mshel_s *ms);
int check_space(char *buffer);
void env_f(mshel_s *ms);

#endif
