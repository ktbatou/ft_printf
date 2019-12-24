/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:24:58 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/24 15:29:49 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_size(char *str, int n)
{
	int	i;

	i = 0;
	while (str[n++] != 'p')
		i++;
	return (i);
}

int		get_det(char *s1, char *str, int i)
{
	int			n;
	t_detail	detail;
	t_valeur	v;

	n = 0;
	intial(&detail, &v);
	while (s1[i] != 'p')
	{
		if (s1[i] == '-')
			detail.minus = 1;
		if (s1[i] >= 48 && s1[i] <= 57)
		{
			if (!v.num)
				v.num = ft_strnew(f_size(s1, i));
			v.num[n++] = s1[i];
		}
		if (s1[i] == '.')
		{
			v.pre = ft_strnew(pre_size(s1, i + 1));
			i += prec(s1, i + 1, v);
			detail.point = 1;
		}
		i++;
	}
	return (print_p(&v, str, detail));
}

int		print_p(t_valeur *v, char *str, t_detail d)
{
	int		n;

	n = ft_strlen(str) + 2;
	v->a = 0;
	if (d.point == 1 && ft_atoi(v->pre) > ft_strlen(str))
		n -= 2;
	v->n = n;
	if (v->num)
		v->i = ft_atoi(v->num);
	if (v->pre)
	{
		v->j = ft_atoi(v->pre);
		if (v->j > n)
			n = v->j;
		if (v->j == 0)
			n = 0;
		v->j -= v->n;
	}
	if (v->i > n)
		v->i -= n;
	else
		v->i = 0;
	v->a = v->i;
	p_conv(d, *v, str);
	return (v->a + n);
}

int		size_p(unsigned long long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int		conv_p(char *str, va_list s2, int n)
{
	unsigned long long int	adr;
	int						i;
	char					*s;

	adr = va_arg(s2, unsigned long long int);
	i = size_p(adr);
	s = ft_strnew(i);
	s[i--] = '\0';
	while (i >= 0)
	{
		if ((adr % 16) >= 10)
			s[i--] = ((adr % 16) % 10) + 'a';
		else
			s[i--] = (adr % 16) + '0';
		adr /= 16;
	}
	return (get_det(str, s, n));
}
