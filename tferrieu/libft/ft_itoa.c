/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:40:41 by tferrieu          #+#    #+#             */
/*   Updated: 2018/11/15 18:33:29 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_init_nbstr(int *nb, char **str)
{
	int i;
	int n;

	i = 1;
	n = *nb;
	while (n > 9 || n < -9)
	{
		n /= 10;
		i++;
	}
	if (!(*str = (char *)malloc(sizeof(char) * (i + (*nb < 0 ? 2 : 1)))))
		return (0);
	if (*nb < 0 && *nb != -2147483648)
	{
		*str[0] = '-';
		*nb *= -1;
		i++;
	}
	return (i);
}

static char	*ft_intmin(void)
{
	char	*val;

	if (!(val = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	val[0] = '-';
	val[1] = '2';
	val[2] = '1';
	val[3] = '4';
	val[4] = '7';
	val[5] = '4';
	val[6] = '8';
	val[7] = '3';
	val[8] = '6';
	val[9] = '4';
	val[10] = '8';
	val[11] = '\0';
	return (val);
}

char		*ft_itoa(int n)
{
	int		i;
	int		nb;
	int		k;
	char	*res;

	nb = n;
	if (nb == -2147483648)
		return (ft_intmin());
	if (!(i = ft_init_nbstr(&nb, &res)))
		return (NULL);
	k = i - 1;
	if (n == 0)
		res[0] = '0';
	while (nb /= 10 > 0)
	{
		res[k] = nb % 10 + 48;
		nb /= 10;
		k--;
	}
	res[i] = '\0';
	return (res);
}
