/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:28:32 by tferrieu          #+#    #+#             */
/*   Updated: 2019/01/08 19:06:40 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "tetriminos.h"

static int	check_tetri(char *buff)
{
	int c[3];
	int i;

	c[0] = 0;
	c[1] = 0;
	i = 0;
	while (buff[i] && i < 21)
	{
		c[2] = 0;
		if (!buff[i] || (buff[i] != 35 && buff[i] != 46 && buff[i] != 10) ||
				(buff[i] == 10 && !((i + 1) % 5 == 0 || i == 20)))
			return (0);
		if (buff[i] == 35)
		{
			c[2] += i > 0 && buff[i - 1] == 35;
			c[2] += i > 4 && buff[i - 5] == 35;
			c[2] += i < 14 && buff[i + 5] == 35;
			c[2] += buff[i + 1] == 35;
			c[0] += (c[2] > 0);
		}
		c[1] += (c[2] > 1 ? 1 : 0);
		i++;
	}
	return (c[0] == 4 && c[1] > 0 ? 1 : 0);
}

static void	extract_tetri(char *buff, int k, char letter, char ***shape)
{
	int x;
	int y;
	int i;

	i = k;
	y = 0;
	while ((*shape)[y])
	{
		x = 0;
		while ((*shape)[y][x])
		{
			(*shape)[y][x] = buff[i] == 35 ? letter : buff[i];
			x++;
			i++;
		}
		i = i - x + 5;
		y++;
	}
}

static char	**get_tetri(char *buff, int i, int h, int w)
{
	int		k;
	char	**shape;

	k = 0;
	if (!(shape = (char **)malloc(sizeof(char *) * h + 1)))
		return (NULL);
	while (k < h)
	{
		if (!(shape[k] = ft_strnew(w + 1)) || !(k += 1))
			return (NULL);
		shape[k - 1] = ft_memset(shape[k - 1], '.', w);
	}
	shape[k] = 0;
	k = 0;
	while (buff[i + k] != 35 && buff[i + k + 5] != 35 && buff[i + k + 10] != 35
			&& buff[i + k + 15] != 35 && k < 4)
		k++;
	while (ft_strchr(buff + i + k, 10) < ft_strchr(buff + i + k, 35))
		k += 5;
	extract_tetri(buff, i + k, 'A' + i / 21, &shape);
	return (shape);
}

static int	init_tetri(char *buff, int i, t_tetri **tab)
{
	int k;

	if (!(check_tetri(buff + i * 21)) ||
			!(tab[i] = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	(tab[i])->h = 0;
	(tab[i])->w = 0;
	k = 0;
	while (k < 4)
	{
		(tab[i])->w += (buff[i * 21 + k] == 35 || buff[i * 21 + k + 5] == 35
				|| buff[i * 21 + k + 10] == 35 || buff[i * 21 + k + 15] == 35);
		k++;
	}
	while (k < 20)
	{
		(tab[i])->h += (buff[i * 21 + k - 1] == 35 ||
				buff[i * 21 + k - 2] == 35 || buff[i * 21 + k - 3] == 35 ||
				buff[i * 21 + k - 4] == 35);
		k += 5;
	}
	if (!((tab[i])->shape = get_tetri(buff, i * 21, (tab[i])->h, (tab[i])->w)))
		return (0);
	return (1);
}

int			check_fillit(int fd, t_tetri ***tab)
{
	int		rd;
	int		i;
	char	*buff;

	if (!(buff = ft_strnew(546)))
		return (0);
	if (((rd = read(fd, buff, 546)) + 1) % 21 || rd >= 546)
		return (0);
	if (!(*tab = (t_tetri **)malloc(sizeof(t_tetri *) * ((rd + 1) / 21 + 1))))
		return (0);
	i = 0;
	while (i < (rd + 1) / 21)
	{
		(*tab)[i] = NULL;
		if (!(init_tetri(buff, i, *tab)))
			return (0);
		((*tab)[i])->status = 1;
		i++;
	}
	(*tab)[i] = NULL;
	return ((rd + 1) / 21);
}
