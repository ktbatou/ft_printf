/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:11:03 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/08 18:43:26 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const t_data g_struct =
{
	{"csxpXdiuo%"},
	{&conv_c, &conv_s, &conv_x, &conv_p, &conv_xx, &conv_d, &conv_i, &conv_u, &conv_o, &percent}

};

int		ft_printf(char *str, ...)
{
	int		i;
	int		format;
	char	*s;
	t_valeur v;
	va_list	ap;

	i = 0;
	format = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			format = ft_check(str, i + 1, ap, v);
			i += (format - i) + 1;
		}
		if (str[i]  != '%' && str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	va_end(ap);
	return (v.f);
}

int		ft_check(char *str, int n, va_list op, t_valeur v)
{
	t_data		data;

	v.f = 0;
	v.a = 0;
	v.i = n;
	data = g_struct;
	while (str[n])
	{
		v.j = 0;
		while (v.j < 10)
		{
			if (data.flags[v.j] == str[n])
			{
				v.f += data.flag[v.j](str, op, v.i);
				v.a = 1;
				break ;
			}
			v.j++;
		}
		if (v.a == 1)
			break ;
		n++;
	}
	return (n);
}
