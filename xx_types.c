/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:48:51 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/26 10:32:05 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_detail	xx_flag(char *str, int n)
{
	t_detail det;

	det.l = 0;
	det.h = 0;
	while (str[n] != 'X')
	{
		if (str[n] == 'l')
			det.l++;
		if (str[n] == 'h')
			det.h++;
		n++;
	}
	return (det);
}

char		*xx_conv_flag(t_detail det, t_unsigned_v v)
{
	char	*num;

	if (det.l == 1)
		num = ft_itoa_base(v.l, 16, 1);
	else if (det.l == 2)
		num = ft_itoa_base(v.ll, 16, 1);
	else if (det.h == 1)
		num = ft_itoa_base(v.h, 16, 1);
	else if (det.h == 2)
		num = ft_itoa_base(v.hh, 16, 1);
	else
		num = ft_itoa_base(v.i, 16, 1);
	return (num);
}

void		xx_types(t_unsigned_v *v, t_detail d, va_list s2)
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
