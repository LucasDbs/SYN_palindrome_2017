/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Opt functions
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"

int opt_n(char *str, arg_s *arg, char *reverse, char *convert)
{
	char *tmp = strdup(str);
	int it = 0;

	if (tmp == NULL)
		return (1);
	while (arg->min++ <= arg->max) {
		if (is_palindrome(tmp) == 0) {
			free_all(reverse, convert);
			return (n_print(tmp, str, it, arg->base));
		}
		convert = base_transform(tmp, 10, arg->base);
		reverse = revstr(convert, 1);
		tmp = add_str(convert, reverse, arg->base);
		it++;
	}
	free(str);
	free(tmp);
	free_all(reverse, convert);
	return (printf("no solution\n"));
}

int test_pr(char *str, arg_s *arg, int *it)
{
	char *convert = NULL;
	char *reverse = NULL;
	char *tmp = strdup(str);

	while (arg->min++ <= arg->max) {
		if (strcmp(tmp, arg->pal) == 0)
			return (0);
		convert = base_transform(tmp, 10, arg->base);
		reverse = revstr(convert, 1);
		tmp = add_str(convert, reverse, arg->base);
		arg->min++;
		(*it)++;
	}
	return (1);
}

int opt_p(arg_s *arg)
{
	int nb = 0;
	char *str = int_to_str(nb);
	int it = 0;

	while (strcmp(str, arg->pal) != 0) {
		if (test_pr(str, arg, &it) == 0)
			p_print(str, arg, it);
		it = 0;
		nb++;
		str = int_to_str(nb);
		arg->min = 0;
	}
	return (p_print(str, arg, it));
}

int manage_opt(arg_s *arg)
{
	char *reverse = NULL;
	char *convert = NULL;

	if (arg->nb != NULL)
		opt_n(arg->nb, arg, reverse, convert);
	else 
		opt_p(arg);
	return (0);
}
