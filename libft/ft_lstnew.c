/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:10:14 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/18 17:55:19 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cont;

	new = NULL;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(cont = (void *)malloc(content_size)))
		return (NULL);
	new->content = cont;
	if (!(content))
	{
		new->content_size = 0;
		free(new->content);
		new->content = NULL;
	}
	else
	{
		new->content_size = content_size;
		new->content = ft_memcpy(new->content, content, content_size);
	}
	new->next = NULL;
	return (new);
}
