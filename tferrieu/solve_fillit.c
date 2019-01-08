/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 16:52:24 by magrab            #+#    #+#             */
/*   Updated: 2019/01/08 13:25:57 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

static void	remove_tetri(char **map, t_tetri *tetri, int x, int y)
{
	int		rx;
	int		ry;
	char	**sp;

	ry = 0;
	sp = tetri->shape;
	while (ry < tetri->h)
	{
		rx = 0;
		while (rx < tetri->w)
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
			if (!map[y + ry][x + rx] || (map[y + ry][x + rx] != '.' &&
						shape[ry][rx] != '.'))
			{
				remove_tetri(map, tetri, x, y);
				return (1);
			}
			if (map[y + ry][x + rx] == '.')
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
	printf("\t\t%d\tSolving...\n", curr_tetri);
	while (try && y > size - (tab[curr_tetri])->h)
	{
		printf("\t\t%d\tPlacing tetri at %d | %d\n", curr_tetri, x, y);
		if ((try = add_tetri(map, tab[curr_tetri], x, y) == 0))
		{
			printf("\t\t%d\tPlaced tetri at %d | %d\n", curr_tetri, x, y);
			if ((try = try_fillit(map, size, tab, curr_tetri + 1)) == 0)
				return (0);
			printf("\t\t%d\tCouldn't place next tetri, removing current tetri at %d | %d\n", curr_tetri, x, y);
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
	printf("\tGetting minimum size\n");
	while (size * size < nb_tetri * 4)
		size++;
	printf("\tMinimum size for %d tetris : %dx%d\n",nb_tetri, size, size);
	while (try)
	{
		printf("\tInitializing map with size %dx%d\n", size, size);
		if (!(map = ft_2dchar_make(size, size)))
			return (NULL);
		printf("\tStarting solve algorithm on current map\n");
		try = try_fillit(map, size, tab, 0);
		if (try && size++)
		{
			printf("\tSolving failed, increasing map size\n");
			ft_2dchar_free(&map);
		}
	}
	return (map);
}
