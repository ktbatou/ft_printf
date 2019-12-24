/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:52:34 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/22 13:20:24 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_count(long long int n)
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

static char			*ft_nbtoa(unsigned long long int nn, char *str, int nb, int i)
{
	str[nb] = '\0';
	while (nb > i)
	{
		str[--nb] = '0' + (nn % 10);
		nn /= 10;
	}
	return (str);
}

 char			*ft_ntoa(long long int n)
{
	unsigned long long int	nn;
	int						i;
	long long int			nb;
	char					*str;

	i = 0;
	nb = ft_count(n);
	if (!(str = (char *)malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		nn = n * -1;
	}
	else
		nn = n;
	if (nn <= 9)
	{
		str[i] = '0' + nn;
		str[++i] = '\0';
	}
	if (nn > 9)
		str = ft_nbtoa(nn, str, nb, i);
	return (str);
}
