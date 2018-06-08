/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Main function
*/

#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"

int main(int ac, char **av)
{
	arg_s *arg = default_arg();

	if (arg == NULL || pars_opt(ac, av, arg) == 1)
		return (84);
	else {
		manage_opt(arg);
		free(arg->nb);
		free(arg->pal);
		free(arg);
		return (0);
	}
	return (0);
}
