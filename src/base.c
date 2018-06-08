/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Basic functions
*/

#include <stdlib.h>
#include <string.h>
#include "palindrome.h"

char *base_transform(char *convert, int act_base, int base)
{
	int new_nb = strtol(convert, NULL, act_base);
	char *res = malloc(sizeof(char) * strlen(convert) + 1);
	int a = 0;
	int save = 0;

	while (new_nb > 0) {
		save = new_nb / base;
		res[a++] = (new_nb - (base * save)) + '0';
		new_nb = save;
	}
	res[a] = '\0';
	return (revstr(res));
}

char *equal(char *str, int lenght)
{
	char *res = malloc(sizeof(char) * (lenght + 1));
	int i = strlen(str) - 1;
	int a = 0;

	while (i >= 0)
		res[a++] = str[i--];
	while (a != (lenght))
		res[a++] = '0';
	res[a] = '\0';
	return (revstr(res));
}

int calc_base(char *res, char *str1, char *str2, int base)
{
	int i = strlen(str1) - 1;
	int a = 0;
	int save = 0;
	int retenu = 0;

	while (i >= 0) {
		save = (str1[i] - '0') + (str2[i] - '0') + retenu;
		if (save >= base) {
			retenu = 1;
			res[a++] = '0';
		} else {
			res[a++] = save + '0';
			retenu = 0;
		}
		i--;
	}
	if (retenu == 1)
		res[a++] = '1';
	res[a] = '\0';
	return (retenu);
}

char *add_str(char *str1, char *str2, int base)
{
	char *res = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));

	if (strlen(str1) > strlen(str2))
		str2 = equal(str2, strlen(str1));
	else if (strlen(str1) < strlen(str2))
		str1 = equal(str1, strlen(str2));
	calc_base(res, str1, str2, base);
	return (revstr(res));
}
