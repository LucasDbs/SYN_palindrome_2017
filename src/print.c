/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Print functions
*/

#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"

int n_print(char *tmp, char *s, int i, int b)
{
	int r = strtol(tmp, NULL, b);

	printf("%s leads to %d in %d iteration(s) in base %d\n", s, r, i, b);
	free(tmp);
	return (0);	
}

int p_print(char *str, arg_s *arg, int i)
{
	printf("%s leads to %s in %d iteration(s) in base %d\n", str, arg->pal, i, arg->base);
	return (0);	
}