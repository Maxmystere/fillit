/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:13:40 by tferrieu          #+#    #+#             */
/*   Updated: 2019/01/06 19:44:28 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# include "libft/libft.h"

typedef struct	s_tetri
{
	char		**shape;
	int			h;
	int			w;
	int			status;
}				t_tetri;

int				add_tetri(char **map, t_tetri *tetri, int x, int y);
void			remove_tetri(char **map, t_tetri *tetri, int x, int y);

int				check_fillit(char **buff, int fd, t_tetri ***tab);
char			**solve_fillit(t_tetri **tab, int nb_tetri);

#endif
