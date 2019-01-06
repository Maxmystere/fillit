/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:28:36 by tferrieu          #+#    #+#             */
/*   Updated: 2018/12/18 17:52:23 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_table_to_list(char **table, int len)
{
	int		i;
	t_list	*res;

	if (!(res = ft_lstnew(table[len - 1], ft_strlen(table[len - 1]))))
		return (NULL);
	i = len - 1;
	while (i > 0)
	{
		i--;
		ft_lstadd(&res, ft_lstnew(table[i], ft_strlen(table[i])));
	}
	return (res);
}
