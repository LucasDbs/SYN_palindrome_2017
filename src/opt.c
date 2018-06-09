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

int manage_min(arg_s *arg, char **tmp, char *reverse, char *convert)
{
	int nb = arg->min;

	arg->min = 0;
	while (arg->min < nb) {
		convert = base_transform(*tmp, 10, arg->base, 0);
		reverse = revstr(convert, 1);
		*tmp = add_str(convert, reverse, arg->base);
		arg->it++;
		arg->min++;
	}
	return (0);
}

int opt_n(arg_s *arg, char *reverse, char *convert)
{
	char *tmp = strdup(arg->nb);

	if (tmp == NULL)
		return (1);
	manage_min(arg, &tmp, reverse, convert);
	while (arg->min <= arg->max) {
		if (is_palindrome(tmp) == 0) {
			free_all(reverse, convert);
			return (n_print(tmp, arg->nb, arg->it, arg->base));
		}
		convert = base_transform(tmp, 10, arg->base, 0);
		reverse = revstr(convert, 1);
		tmp = add_str(convert, reverse, arg->base);
		arg->it++;
		arg->min++;
	}
	free(tmp);
	free_all(reverse, convert);
	return (printf("no solution\n"));
}

int check_t(char *str, arg_s *arg)
{
	char *convert = NULL;
	char *reverse = NULL;
	char *tmp = strdup(str);

	manage_min(arg, &tmp, reverse, convert);
	while (arg->min <= arg->max) {
		if (strcmp(tmp, arg->pal) == 0)
			return (0);
		convert = base_transform(tmp, 10, arg->base, 0);
		reverse = revstr(convert, 1);
		tmp = add_str(convert, reverse, arg->base);
		arg->min++;
		arg->it++;
	}
	return (1);
}

int opt_p(arg_s *arg)
{
	int nb = 1;
	char *str = int_to_str(nb);
	int save = arg->min;
	int no = 0;

	while (strcmp(str, arg->pal) != 0) {
		if (check_t(str, arg) == 0) {
			p_print(str, arg);
			no++;
		}
		arg->it = 0;
		nb++;
		str = int_to_str(nb);
		arg->min = save;
	}
	return (no != 0 ? (p_print(str, arg)) : (printf("no solution\n")));
}

int manage_opt(arg_s *arg)
{
	char *reverse = NULL;
	char *convert = NULL;

	if (arg->nb != NULL)
		opt_n(arg, reverse, convert);
	else {
		if (arg->min == 0 && arg->max == 0)
			return (p_print("0", arg));
		opt_p(arg);
	}
	return (0);
}
