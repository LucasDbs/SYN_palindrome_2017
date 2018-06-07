/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Struct functions
*/

#include <stdlib.h>
#include "palindrome.h"

arg_s *default_arg(void)
{
	arg_s *new = malloc(sizeof(arg_s));

	if (new == NULL)
		return (NULL);
	new->nb = -1;
	new->pal = -1;
	new->base = -1;
	new->min = 0;
	new->max = 100;
	return (new);
}
