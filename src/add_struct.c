/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Add arg to struct
*/

#include <stdlib.h>
#include "palindrome.h"

#include <stdio.h>

int add_nb(arg_s * arg, char *to_add)
{
	if (is_valid(to_add) == 0) {
		arg->nb = atoi(to_add);
		return (0);
	} else
		return (1);
}

int add_pal(arg_s * arg, char *to_add)
{
	if (is_valid(to_add) == 0) {
		arg->pal = atoi(to_add);
		return (0);
	} else
		return (1);
	return (0);
}

int add_base(arg_s * arg, char *to_add)
{
	if (is_valid(to_add) == 0) {
		arg->base = atoi(to_add);
		return (0);
	} else
		return (1);
	return (0);
}

int add_min(arg_s * arg, char *to_add)
{
	if (is_valid(to_add) == 0) {
		arg->min = atoi(to_add);
		return (0);
	} else
		return (1);
	return (0);
}

int add_max(arg_s * arg, char *to_add)
{
	if (is_valid(to_add) == 0) {
		arg->max = atoi(to_add);
		return (0);
	} else
		return (1);
	return (0);
}
