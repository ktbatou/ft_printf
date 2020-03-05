/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kawtarfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:07:02 by amassnao          #+#    #+#             */
/*   Updated: 2020/03/05 17:07:09 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

int			checker_f(t_detail *d, t_valeur *v, char *s, int n)
{
	int i;

	i = 0;
	(s[n] == '#') ? d->hash = 1 : 0;
	if (s[n] == '+' && d->signe == 1)
		d->plus = 1;
	(s[n] == '-') ? d->minus = 1 : 0;
	if (s[n] == ' ' && d->signe == 1)
		d->space = 1;
	if (s[n] >= '0' && s[n] <= '9')
	{
		if (!v->num)
			v->num = ft_strnew(v->i);
		if (s[n] == '0' && v->flag == 0)
			d->zero = 1;
		v->flag = 1;
		v->num[v->j++] = s[n];
	}
	if (s[n] == '.')
	{
		v->pre = ft_strnew(pre_size(s, n + 1));
		i = pre_size(s, n + 1) > 0 ? prec(s, n + 1, *v) : 0;
		d->point = 1;
	}
	return (i);
}

int			string_size_f(char *str, int n)
{
	int	i;

	i = 0;
	while (str[n] != 'f')
	{
		if (str[n] >= '0' && str[n] <= '9')
			i++;
		n++;
	}
	return (i);
}

void		f_detail(char *str, int n, t_valeur *v, t_detail *d)
{
	v->i = string_size_f(str, n);
	while (str[n] != 'f')
	{
		n += checker_f(d, v, str, n);
		n++;
	}
}

long int	ft_atol(const char *str, t_bool use_max_int, int def)
{
	int			i;
	long int	nb;
	int			bolean;

	bolean = 0;
	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		bolean = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (str[i] - '0') + (nb * 10);
		i++;
	}
	if (!use_max_int)
		return ((bolean == 1) ? -nb : nb);
	else
		return ((nb > INT_MAX) ? def : nb);
}

void		ft_putchar_seq(char c, int seq)
{
	while (seq-- > 0)
		ft_putchar(c);
}
