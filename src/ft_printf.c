/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:46:47 by ktbatou           #+#    #+#             */
/*   Updated: 2020/03/05 16:42:35 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	int			format;
	t_valeur	v;
	va_list		ap;

	v.f = 0;
	v.i = 0;
	format = 0;
	v.n = 0;
	va_start(ap, str);
	while (str[v.i])
	{
		if (str[v.i] == '%')
		{
			format = ft_check(str, v.i + 1, ap, &v);
			v.i += (format - v.i) + 1;
			format++;
		}
		if (str[v.i] && str[v.i] != '%')
		{
			ft_putchar(str[v.i++]);
			v.n++;
		}
	}
	va_end(ap);
	return (v.f + v.n);
}

int		ft_check(char *str, int n, va_list op, t_valeur *v)
{
	t_data		data;

	v->a = 0;
	v->i = n;
	fill_struct(&data);
	while (str[n])
	{
		v->j = 0;
		while (v->j < 11)
		{
			if (data.flags[v->j] == str[n])
			{
				v->f += data.flag[v->j](str, op, v->i);
				v->a = 1;
				break ;
			}
			v->j++;
		}
		if (v->a == 1)
			break ;
		n++;
	}
	return (n);
}

void	fill_struct(t_data *data)
{
	ft_strcpy(data->flags, "csxpXdiuo%f");
	data->flag[0] = &conv_c;
	data->flag[1] = &conv_s;
	data->flag[2] = &conv_x;
	data->flag[3] = &conv_p;
	data->flag[4] = &conv_xx;
	data->flag[5] = &conv_d;
	data->flag[6] = &conv_i;
	data->flag[7] = &conv_u;
	data->flag[8] = &conv_o;
	data->flag[9] = &percent;
	data->flag[10] = &conv_f;
}
