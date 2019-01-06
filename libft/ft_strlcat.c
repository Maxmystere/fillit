/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:57:45 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/18 17:53:04 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			len_dst;
	size_t			result;
	unsigned int	k;

	k = 0;
	len_dst = ft_strlen(dst);
	result = ft_strlen(src);
	if (size > len_dst)
		result += len_dst;
	else
		result += size;
	while (src[k] && len_dst + 1 < size)
	{
		dst[len_dst] = src[k];
		len_dst++;
		k++;
	}
	dst[len_dst] = '\0';
	return (result);
}
