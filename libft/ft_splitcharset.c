/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcharset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:43:14 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/18 17:54:03 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_wlen(char const *s, char *charset, int start)
{
	int i;

	i = 0;
	while (s[i + start] && !(is_charset(s[i + start], charset)))
		i++;
	return (i);
}

static int	wc(char const *s, char *charset)
{
	int i;
	int count;
	int b;

	i = 0;
	b = 0;
	count = 0;
	while (s[i])
	{
		if (!(is_charset(s[i], charset)) && !b)
		{
			count++;
			b = 1;
		}
		else if (is_charset(s[i], charset) && b)
			b = 0;
		i++;
	}
	return (count);
}

char		**ft_splitcharset(char const *s, char *set)
{
	char	**tab;
	int		k;
	int		i;

	if (s)
	{
		if (!(tab = (char**)malloc(sizeof(char*) * (wc(s, set) + 1))))
			return (NULL);
		k = 0;
		i = 0;
		while (k < wc(s, set))
		{
			if (!(is_charset(s[i], set)))
			{
				tab[k] = ft_strsub(s, i, ft_wlen(s, set, i));
				i += ft_wlen(s, set, i);
				k++;
			}
			i++;
		}
		tab[k] = 0;
		return (tab);
	}
	return (NULL);
}
