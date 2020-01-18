/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_types.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:17:43 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/25 13:04:27 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_detail	x_flag(char *str, int n)
{
	t_detail det;

	det.l = 0;
	det.h = 0;
	while (str[n] != 'x')
	{
		if (str[n] == 'l')
			det.l++;
		if (str[n] == 'h')
			det.h++;
		n++;
	}
	return (det);
}

char		*x_conv(t_unsigned_v v, t_detail det)
{
	char	*num;

	if (det.l == 1)
		num = ft_itoa_base(v.l, 16, 0);
	else if (det.l == 2)
		num = ft_itoa_base(v.ll, 16, 0);
	else if (det.h == 1)
		num = ft_itoa_base(v.h, 16, 0);
	else if (det.h == 2)
		num = ft_itoa_base(v.hh, 16, 0);
	else
		num = ft_itoa_base(v.i, 16, 0);
	return (num);
}

void		x_types(va_list s2, t_unsigned_v *v, t_detail d)
{
	if (d.l == 1)
	{
		if ((v->l = va_arg(s2, unsigned long int)) != 0)
			v->signe = 1;
	}
	else if (d.l == 2)
	{
		if ((v->ll = va_arg(s2, unsigned long long int)) != 0)
			v->signe = 1;
	}
	else if (d.h == 1)
	{
		if ((v->h = (unsigned short int)va_arg(s2, unsigned int)) != 0)
			v->signe = 1;
	}
	else if (d.h == 2)
	{
		if ((v->hh = (unsigned char)va_arg(s2, unsigned int)) != 0)
			v->signe = 1;
	}
	else
	{
		if ((v->i = va_arg(s2, unsigned int)) != 0)
			v->signe = 1;
	}
}
