/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Ptr functions
*/

#include <stdlib.h>
#include "palindrome.h"

ptr_s init_struct(char c, int (*ptr)(arg_s *, char *))
{
	ptr_s new;

	new.c = c;
	new.ptr = ptr;
	return (new);
}

ptr_s *init_ptr(void)
{
	ptr_s *new = malloc(sizeof(ptr_s) * 5);

	new[0] = init_struct('n', &add_nb);
	new[1] = init_struct('p', &add_pal);
	new[2] = init_struct('b', &add_base);
	new[3] = init_struct('i', &add_min);
	new[4] = init_struct('a', &add_max);
	return (new);
}

int add_to_struct(arg_s *arg, char c, char *optarg)
{
	ptr_s *check = init_ptr();
	int a = 0;

	while (a != 5) {
		if (c == check[a].c)
			return (check[a].ptr(arg, optarg));
		a++;
	}
	return (0);
}
