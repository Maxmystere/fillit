/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:13:35 by tferrieu          #+#    #+#             */
/*   Updated: 2018/11/15 17:34:19 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int i;

	i = 0;
	while (i < (int)(n / sizeof(*src)))
	{
		*((unsigned char *)dst) = *((unsigned char *)(src + i));
		i++;
		dst++;
	}
	return (dst - i);
}
