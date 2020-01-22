/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_pre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:36:24 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/23 13:59:41 by ktbatou          ###   ########.fr       */
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

int		pre_vlr(t_valeur *v, t_valeur vl, int n)
{
	v->j = ft_atoi(v->pre);
	if (v->j > n)
	{
		n = v->j;
		if (vl.j == 0)
			n++;
	}
	if (v->j == 0)
		n = 0;
	v->j -= v->n;
	return (n);
}