/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:48:58 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/18 17:52:08 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int k;
	int gap;

	i = 0;
	if (!(ft_strlen(needle)))
		return ((char *)haystack);
	while (haystack[i])
	{
		k = 0;
		gap = 0;
		while (haystack[i + gap] && needle[k] && haystack[i + gap] == needle[k])
		{
			gap++;
			k++;
			if (needle[k] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
