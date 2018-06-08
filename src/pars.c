/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Parsing functions
*/

#include <getopt.h>
#include <stdio.h>
#include "palindrome.h"

int last_check(arg_s *arg)
{
	if (is_palindrome(arg->pal) == 1)
		return (error());
	else if (arg->nb == NULL && arg->pal == NULL)
		return (error());
	else
		return (0);
}

int check_struct(arg_s *arg)
{
	if (arg->nb != NULL && arg->pal != NULL)
		return (error());
	else if ((arg->base > 10 || arg->base < 1)
		|| (arg->min > arg->max))
		return (error());
	else
		return (last_check(arg));
}

struct option *init_option()
{
	static struct option new[] =
		{{"n", 1, NULL, 'n'},
		{"p", 1, NULL, 'p'},
		{"b", 1, NULL, 'b'},
		{"imin", 1, NULL, 'i'},
		{"imax", 1, NULL, 'a'},
		{0, 0, 0, 0}};
	return (new);
}

int pars_opt(int ac, char **av, arg_s *arg)
{
	struct option *tab_opt = init_option();
	int c = 0;

	opterr = 0;
	while ((c = getopt_long_only(ac, av, "", tab_opt, NULL)) != -1) {
		if (c == '?')
			return (error());
		else if (add_to_struct(arg, c, optarg) == 1)
			return (1);
	}
	return (check_struct(arg));
}
