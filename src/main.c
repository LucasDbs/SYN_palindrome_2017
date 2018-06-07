/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Main function
*/

#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

int main(int ac, char **av)
{
	arg_s *arg = default_arg();

	if (arg == NULL || pars_opt(ac, av, arg) == 1)
		return (84);
	return (0);
}
