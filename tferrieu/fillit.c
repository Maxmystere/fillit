/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:29:12 by tferrieu          #+#    #+#             */
/*   Updated: 2019/01/08 18:43:18 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "tetriminos.h"

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
	return (0);
}
