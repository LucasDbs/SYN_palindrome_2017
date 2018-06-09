/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Free functions
*/

#include <stdlib.h>

int free_all(char *reverse, char *convert)
{
	free(convert);
	free(reverse);
	return (0);
}
