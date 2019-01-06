/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:28:02 by tferrieu          #+#    #+#             */
/*   Updated: 2019/01/06 19:19:08 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void	remove_tetri(char **map, t_tetri *tetri, int x, int y)
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
			if (sp[ry][rx] == map[y +ry][x + rx])
				map[y + ry][x + rx] = '.';
			rx++;
		}
		ry++;
	}
}

int		add_tetri(char **map, t_tetri *tetri, int x, int y)
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
		ry ++;
	}

}
