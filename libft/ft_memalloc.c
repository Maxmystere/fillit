/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:42:02 by tferrieu          #+#    #+#             */
/*   Updated: 2018/11/15 17:34:47 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	int		i;

	i = 0;
	if (!(mem = (void*)malloc(size)))
		return (NULL);
	while (i < (int)(size / sizeof(char)))
	{
		*(char *)(mem + i) = 0;
		i++;
	}
	return (mem);
}
