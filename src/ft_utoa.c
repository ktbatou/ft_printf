/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:52:34 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/27 16:18:47 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count(unsigned int n)
{
	int nb;

	nb = 0;
	if (n <= 0)
		nb++;
	while (n != 0)
	{
		n /= 10;
		nb++;
	}
	return (nb);
}

static char		*ft_nntoa(unsigned int nn, char *str, int nb, int i)
{
	str[nb] = '\0';
	while (nb > i)
	{
		str[--nb] = '0' + (nn % 10);
		nn /= 10;
	}
	return (str);
}

char			*ft_utoa(unsigned int n)
{
	unsigned int	nn;
	int				i;
	int				nb;
	char			*str;

	i = 0;
	nb = ft_count(n);
	nn = n;
	if (!(str = (char *)malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	if (nn <= 9)
	{
		str[i] = '0' + nn;
		str[++i] = '\0';
	}
	if (nn > 9)
		str = ft_nntoa(nn, str, nb, i);
	return (str);
}
