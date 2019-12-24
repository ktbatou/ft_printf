/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:52:34 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/22 13:20:23 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long int		count(unsigned long long int n)
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

static char						*ft_iitoa(unsigned long long int nn, char *str, int nb, int i)
{
	str[nb] = '\0';
	while (nb > i)
	{
		str[--nb] = '0' + (nn % 10);
		nn /= 10;
	}
	return (str);
}

char						*ft_untoa(unsigned long long int n)
{
	unsigned long long int	nn;
	int						i;
	unsigned long long int	nb;
	char					*str;

	i = 0;
	nb = count(n);
	if (!(str = (char *)malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	if (n <= 9)
	{
		str[i] = '0' + n;
		str[++i] = '\0';
	}
	if (n > 9)
		str = ft_iitoa(n, str, nb, i);
	return (str);
}
