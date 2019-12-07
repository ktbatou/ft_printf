/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_pre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:36:24 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/07 17:10:23 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pre_size(char *str, int n)
{
	int i;

	i = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		i++;
		n++;
	}
	return (i);
}

int		prec(char *str, int n, char **num)
{
	int i;

	i = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		*num[i++] = str[n];
		n++;
	}
	return (i);
}
