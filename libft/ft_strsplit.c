/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:55:16 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/18 17:52:00 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_wlen(char const *s, char c, int start)
{
	int i;

	i = 0;
	while (s[i + start] && s[i + start] != c)
		i++;
	return (i);
}

static int	wc(char const *s, char c)
{
	int i;
	int count;
	int b;

	i = 0;
	b = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && !b)
		{
			count++;
			b = 1;
		}
		else if (s[i] == c && b)
			b = 0;
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		k;
	int		i;

	if (s)
	{
		if (!(tab = (char**)malloc(sizeof(char*) * (wc(s, c) + 1))))
			return (NULL);
		k = 0;
		i = 0;
		while (k < wc(s, c))
		{
			if (s[i] != c)
			{
				if (!(tab[k] = ft_strsub(s, i, ft_wlen(s, c, i))))
					return (NULL);
				i += ft_wlen(s, c, i);
				k++;
			}
			i++;
		}
		tab[k] = 0;
		return (tab);
	}
	return (NULL);
}
