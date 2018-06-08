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
	new->nb = NULL;
	new->pal = NULL;
	new->base = 10;
	new->min = 0;
	new->max = 100;
	return (new);
}
