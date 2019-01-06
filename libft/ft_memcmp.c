/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:00:36 by tferrieu          #+#    #+#             */
/*   Updated: 2018/11/15 17:20:34 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*r1;
	unsigned char	*r2;

	r1 = (unsigned char*)s1;
	r2 = (unsigned char*)s2;
	i = 0;
	while (i < (int)(n / sizeof(char)))
	{
		if (*(r1 + i) != *(r2 + i))
			return ((int)(*(r1 + i) - *(r2 + i)));
		i++;
	}
	return (0);
}
