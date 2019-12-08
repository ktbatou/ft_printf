/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_pre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:36:24 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/08 18:31:37 by ktbatou          ###   ########.fr       */
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

int		prec(char *str, int n, t_valeur v)
{
	int i;

	i = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		v.pre[i++] = str[n];
		n++;
	}
	return (i);
}
