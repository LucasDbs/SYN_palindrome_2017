/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Check functions
*/

#include <string.h>

int check_nb(int nb)
{
	int i = 0;

	if (nb < 0)
		nb *= -1;
	while (nb > 10) {
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

int is_palindrome(char *str)
{
	int i = 0;
	int a = 0;

	if (str == NULL)
		return (0);
	a = strlen(str) - 1;
	while (a != 0) {
		if (str[i] != str[a])
			return (1);
		a--;
		i++;
	}
	return (0);
}
