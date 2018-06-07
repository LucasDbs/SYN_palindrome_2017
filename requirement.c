/*
** EPITECH PROJECT, 2018
** Lucas Duboisse
** File description:
** requirement
*/

int my_factrec_synthesis(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	else
		return (nb = nb * my_factrec_synthesis(nb - 1));
}

int my_squareroot_synthesis(int nb)
{
	int root = 0;

	while ((root * root) <= nb)
		root++;
	root--;
	if ((root * root) == nb)
		return (root);
	return (-1);
}
