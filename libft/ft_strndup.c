/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:42:01 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/18 17:51:35 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, int ln)
{
	int		i;
	char	*dup;

	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i] && i < ln)
	{
		dup[i] = s1[i];
		i++;
	}
	while (i <= ln)
	{
		dup[i] = '\0';
		i++;
	}
	return (dup);
}
