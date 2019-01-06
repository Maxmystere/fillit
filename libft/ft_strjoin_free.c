/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:35:20 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/18 17:53:09 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_free(char **s1, char **s2, int d)
{
	char	*res;

	res = ft_strjoin(*((char **)s1), *((char **)s2));
	if (d == 1 || d == 3)
		ft_strdel(s1);
	if (d == 2 || d == 3)
		ft_strdel(s2);
	return (res);
}
