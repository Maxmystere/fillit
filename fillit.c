/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:29:12 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/29 17:22:53 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "tetriminos.h"
#include "libft/libft.h"

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

static int	error_free(t_tetri ***tab, char **res, char **buff)
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
	if (*res)
		ft_strdel(res);
	if (*buff)
		ft_strdel(buff);
	write(1, "error\n", 6);
	return (0);
}

int			main(int ac, char **av)
{
	t_tetri	**tab;
	char	*buff;
	char	*res;
	int		nb_tetri;
	int		fd;
	int		i;
	int		y;

	tab = NULL;
	res = NULL;
	buff = NULL;
	(void)av;
	if (ac != 2 || !((fd = open(av[1], O_RDONLY | O_DIRECTORY)) == -1 &&
				(fd = open(av[1], O_RDONLY)) != -1))
		return (write(1, "usage: ./fillit source_file\n", 28));
	if (!(nb_tetri = check_fillit(&buff, fd, &tab)))
		return (error_free(&tab, &res, &buff));
	i = 0;
	while (tab[i])
	{
		y = 0;
		while (((tab[i])->shape)[y])
		{
			printf("%s\n",((tab[i])->shape)[y]);
			y++;
		}
		if (tab[i + 1] != NULL)
			printf("\n");
		i++;
	}
	return (0);
}
