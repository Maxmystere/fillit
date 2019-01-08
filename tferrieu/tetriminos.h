/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:13:40 by tferrieu          #+#    #+#             */
/*   Updated: 2019/01/08 19:14:25 by tferrieu         ###   ########.fr       */
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

int				check_fillit(int fd, t_tetri ***tab);

#endif
