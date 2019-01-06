/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 16:52:24 by magrab            #+#    #+#             */
/*   Updated: 2019/01/06 19:41:56 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

static int		try_fillit(char ***map, int size, t_tetri **tab, int curr_tetri)
{
	int		try;
	int		x;
	int		y;

	try = -1;
	if (!tab)
		return (0);
	x = 0;
	y = 0;
	while (try)
	{
		try = add_tetri(map, tab[curr_tetri], x, y);
		if ((try = add_tetri(map, tab, x, y) == 0)) // a pu placer
		{
			if ((try = try_fillit(map, size, tab + 1, curr_tetri + 1)) == 0)
				return (0);
			remove_tetri(map, tab[curr_tetri], x, y);
		}
		x++;
		if (x > size - (tab[0])->w)
		{
			x = 0;
			if (++y > size - (tab[0])->h)
				return (-1);
		}
	}
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
		if (!(map = ft_2dchar_make(size, size)))
			return (NULL);
		try = try_fillit(&map, size, tab, 0);
		if (try && size++)
			ft_2dchar_free(&map);
	}
	return (map);
}
