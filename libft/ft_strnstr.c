/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:49:13 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/18 17:51:49 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int k;
	int gap;

	i = 0;
	if (!(ft_strlen(needle)))
		return ((char *)haystack);
	while (haystack[i] && i < (int)len)
	{
		k = 0;
		gap = 0;
		while (haystack[i + gap] && needle[k] && haystack[i + gap] == needle[k]
						&& i + gap < (int)len)
		{
			gap++;
			k++;
			if (needle[k] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
