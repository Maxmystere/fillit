/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:13:40 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/29 17:16:51 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

typedef struct	s_tetri
{
	char			**shape;
	int				h;
	int				w;
	int				status;
}				t_tetri;

int	check_fillit(char **buff, int fd, t_tetri ***tab);

#endif
