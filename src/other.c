/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Basic functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palindrome.h"

char *revstr(char *str, int f)
{
	int i = strlen(str);
	char *new = malloc(sizeof(char) * (i + 1));
	int a = 0;

	i--;
	while (i >= 0)
		new[a++] = str[i--];
	new[a] = '\0';
	if (f == 0)
		free(str);
	return (new);
}

char *int_to_str(int nb)
{
	int size = check_nb(nb);
	int type = 0;
	char *res = malloc(sizeof(char) * (size + 1));

	if (res == NULL)
		return (NULL);
	if (nb < 0) {
		type = 1;
		res[size - 1] = '-';
		nb *= -1;
	}
	for (int cnt = 0; cnt < size - type; cnt++) {
		res[cnt] = (nb % 10) + '0';
		nb /= 10;
	}
	res[size] = '\0';
	return (revstr(res, 0));
}

int error(void)
{
	dprintf(2, "invalid argument\n");
	return (1);
}

int is_valid(char *str)
{
	int i = 0;

	if (strlen(str) > 9)
		return (error());
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (error());
	}
	return (0);
}
