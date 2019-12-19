/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_types.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:48:47 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/19 18:22:45 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		u_types(t_detail d, t_unsigned_v *v, char **num, va_list s2)
{
	if (d.l == 1)
	{
		v->l = va_arg(s2, unsigned long int);
		*num = ft_untoa(v->l);
	}
	else if (d.l == 2)
	{
		v->ll = va_arg(s2, unsigned long long int);
		*num = ft_untoa(v->ll);
	}
	else if (d.h == 1)
	{
		v->h = (unsigned short int)va_arg(s2, unsigned int);
		*num = ft_untoa(v->h);
	}
	else if (d.h == 2)
	{
		v->hh = (unsigned char)va_arg(s2, unsigned int);
		*num = ft_untoa(v->hh);
	}
	else
	{
		v->i = va_arg(s2, unsigned int);
		*num = ft_untoa(v->i);
	}
}

t_detail	flags(char *str, int n)
{
	t_detail det;

	det.l = 0;
	det.h = 0;
	while (str[n] != 'u')
	{
		if (str[n] == 'l')
			det.l++;
		if (str[n] == 'h')
			det.h++;
		n++;
	}
	return (det);
}
