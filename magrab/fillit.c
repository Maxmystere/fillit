/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:29:12 by tferrieu          #+#    #+#             */
/*   Updated: 2019/01/08 18:30:19 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "tetriminos.h"

static void	free_tetri(t_tetri *chain, int *i)
{
	int		k;

	*i += 1;
	k = 0;
	while ((chain->shape)[k])
	{
		free((chain->shape)[k]);
		k++;
	}
	if (chain->shape)
		free(chain->shape);
	if (chain)
		free(chain);
}

static int	error_free(t_tetri ***tab, char ***res)
{
	int i;

	i = 0;
	if (*tab)
	{
		while ((*tab)[i])
			free_tetri((*tab)[i], &i);
		free(*tab);
		*tab = NULL;
	}
	if (**res)
		ft_2dchar_free(res);
	write(1, "error\n", 6);
	return (0);
}

int			main(int ac, char **av)
{
	t_tetri	**tab;
	char	**res;
	int		nb_tetri;
	int		fd;

	tab = NULL;
	res = NULL;
	(void)av;
	if (ac != 2 || !((fd = open(av[1], O_RDONLY | O_DIRECTORY)) == -1 &&
				(fd = open(av[1], O_RDONLY)) != -1))
		return (write(1, "usage: ./fillit source_file\n", 28));
	if (!(nb_tetri = check_fillit(fd, &tab)))
		return (error_free(&tab, &res));
	if (!(res = solve_fillit(tab, nb_tetri)))
		return (error_free(&tab, &res));
	ft_2dchar_print(res);
	return (0);
}
