/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Basic functions
*/

#include <stdio.h>

int error(void)
{
	dprintf(2, "invalid argument\n");
	return (1);
}

int is_valid(char *str)
{
	int i = 0;

	if (str[0] == '-')
		return (error());
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (error());
	}
	return (0);
}
