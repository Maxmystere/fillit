/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 16:52:24 by magrab            #+#    #+#             */
/*   Updated: 2019/01/06 18:17:21 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

static int		try_fillit(char ***map, int size, t_tetri **tab, int nb_tetri)
{

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
		try = try_fillit(&map, size, tab, nb_tetri);
		if (try && size++)
			ft_2dchar_free(&map);
	}
	return (map);
}
