/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:29:12 by tferrieu          #+#    #+#             */
/*   Updated: 2019/01/08 20:50:07 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "tetriminos.h"

static void	remove_tetri(char **map, t_tetri *tetri, int x, int y)
{
	int		rx;
	int		ry;
	char	**sp;

	ry = 0;
	sp = tetri->shape;
	while (ry < tetri->h && map[ry + y])
	{
		rx = 0;
		while (rx < tetri->w && map[ry + y][rx + x])
		{
			if (sp[ry][rx] == map[y + ry][x + rx])
				map[y + ry][x + rx] = '.';
			rx++;
		}
		ry++;
	}
}

static int	add_tetri(char **map, t_tetri *tetri, int x, int y)
{
	int		rx;
	int		ry;
	char	**shape;

	shape = tetri->shape;
	ry = 0;
	while (ry < tetri->h)
	{
		rx = 0;
		while (rx < tetri->w)
		{
			if (!map || !map[y] || !map[y + ry][x + rx] ||
					(map[y + ry][x + rx] != '.' && shape[ry][rx] != '.'))
			{
				remove_tetri(map, tetri, x, y);
				return (1);
			}
			if (shape[ry][rx] != '.')
				map[y + ry][x + rx] = shape[ry][rx];
			rx++;
		}
		ry++;
	}
	return (0);
}

static int	try_fillit(char **map, int size, t_tetri **tab, int curr_tetri)
{
	int		try;
	int		x;
	int		y;

	try = -1;
	if (!tab[curr_tetri])
		return (0);
	x = 0;
	y = 0;
	while (y <= size - (tab[curr_tetri])->h)
	{
		if ((try = add_tetri(map, tab[curr_tetri], x, y) == 0))
		{
			if ((try = try_fillit(map, size, tab, curr_tetri + 1)) == 0)
				return (0);
			remove_tetri(map, tab[curr_tetri], x, y);
		}
		x++;
		if (x > size - (tab[curr_tetri])->w)
		{
			x = 0;
			y++;
		}
	}
	return (-1);
}

char		**solve_fillit(t_tetri **tab, int nb_tetri)
{
	int		size;
	char	**map;
	int		try;

	try = 1;
	size = 2;
	while (size * size < nb_tetri * 4)
		size++;
	while (try)
	{
		if (!(map = ft_2dchar_make(size, size, '.')))
			return (NULL);
		try = try_fillit(map, size, tab, 0);
		if (try && size++)
			ft_2dchar_free(&map);
	}
	size = 0;
	while (tab[size])
	{
		try = 0;
		while (((tab[size])->shape)[try])
			free(((tab[size])->shape)[try++]);
		free(tab[size++]);
	}
	return (map);
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
		return (write(1, "error\n", 6));
	if (!(res = solve_fillit(tab, nb_tetri)))
		return (write(1, "error\n", 6));
	ft_2dchar_print(res);
	ft_2dchar_free(&res);
	free(tab);
	return (0);
}
