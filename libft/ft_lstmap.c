/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:23:53 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/18 17:55:25 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*ld;
	t_list	*tmp;

	new = NULL;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (lst && *f)
	{
		ld = lst;
		new = (*f)(ld);
		tmp = new;
		while (ld->next)
		{
			if (!(tmp->next = (t_list*)malloc(sizeof(t_list))))
				return (NULL);
			tmp->next = (*f)(ld->next);
			ld = ld->next;
			tmp = tmp->next;
		}
	}
	return (new);
}
