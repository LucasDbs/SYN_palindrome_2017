/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Palindrome.h
*/

#ifndef PALINDROME_H_
#define PALINDROME_H_

typedef struct arg_s
{
	char *nb;
	char *pal;
	int base;
	int min;
	int max;
} arg_s;

typedef struct ptr_s
{
	char c;
	int (*ptr)(arg_s *arg, char *);
} ptr_s;

arg_s *default_arg(void);
int pars_opt(int, char **, arg_s *);
int add_nb(arg_s *, char *);
int add_pal(arg_s *, char *);
int add_base(arg_s *, char *);
int add_min(arg_s *, char *);
int add_max(arg_s *, char *);
int add_to_struct(arg_s *, char, char *);
int is_valid(char *);
int error(void);
int manage_opt(arg_s *);
char *revstr(char *);
int check_nb(int);
int is_palindrome(char *);

#endif