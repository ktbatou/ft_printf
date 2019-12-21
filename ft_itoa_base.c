/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:48:00 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/21 16:11:21 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	size_base(unsigned long long int i, int base)
{
	int	j;

	j = 0;
	if (i == 0)
		return (1);
	while (i >= 1)
	{
		i /= base;
		j++;
	}
	return (j);
}

char			*ft_itoa_base(unsigned long long int n, int base, int a)
{
	long long int	i;
	char			*num;
	char			c;

	c = 'a';
	i = size_base(n, base);
	if (a == 1)
		c = 'A';
	num = ft_strnew(i);
	num[i--] = '\0';
	while (i >= 0)
	{
		if ((n % base) >= 10)
			num[i--] = ((n % base) % 10) + c;
		else
			num[i--] = '0' + (n % base);
		n /= base;
	}
	return (num);
}
