/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:54:46 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/18 17:52:15 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		b;
	int		e;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	e = ft_strlen(s) - 1;
	while (e >= 0 && s[e] && (s[e] == ' ' || s[e] == '\t' || s[e] == '\n'))
		e--;
	b = 0;
	while (s[b] && (s[b] == ' ' || s[b] == '\t' || s[b] == '\n') && e > 0)
		b++;
	if (!(str = (char*)malloc(sizeof(char) * (e - b + 2))))
		return (NULL);
	i = 0;
	while (b + i <= e)
	{
		str[i] = s[b + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
