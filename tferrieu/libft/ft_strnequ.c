/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:48:12 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/18 17:51:40 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	if ((ft_strlen(s1) > ft_strlen(s2) && n > ft_strlen(s2)) ||
			(ft_strlen(s2) > ft_strlen(s1) && n > ft_strlen(s1)))
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < (int)n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
