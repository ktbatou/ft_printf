/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:12:16 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/22 18:08:44 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_o(char *str ,char *num, int minus, int hash, int zero)
{
	int		i;
	char	c;

	i = atoi(num);
	c = ' ';
	if (i > ft_strlen(str))
		i -= ft_strlen(str);
	else
		i = 0;
	if (hash == 1)
		i--;
	if (zero == 1 && minus == 0)
		c  ='0';
	if (minus == 1)
	{
		if (hash == 1)
			ft_putchar('0');
		ft_putstr(str);
		while (i-- > 0)
			ft_putchar(c);
	}
	else
	{
		while (i-- > 0)
			ft_putchar(c);
		if (hash == 1)
			ft_putchar('0');
		ft_putstr(str);
	}
}

int		num_size(char *str, int n)
{
	int	 i;

	i = 0;
	while (str[n] != 'o')
	{
		if (str[n] >= '0' && str[n] <= '9')
			i++;
		n++;
	}
	return(i);
}

void	detail_o(char *nb, char *str, int n)
{
	t_detail detail;
	t_valeur v;

	v.j = 0;
	v.flag = 0;
	detail.minus = 0;
	detail.hash = 0;
	detail.zero = 0;
	v.num = ft_strnew(num_size(str, n));
	while (str[n]  != 'o')
	{
		if (str[n] == '-')
			detail.minus = 1;
		if (str[n] == '#')
			detail.hash = 1;
		if (str[n]  >= '0' && str[n] <= '9')
		{
			if (str[n] == '0' && v.flag == 0)
				detail.zero = 1;
			v.flag = 1;
			v.num[v.j++] = str[n];
		}
		n++;
	}
		print_o(nb, v.num, detail.minus, detail.hash, detail.zero);
}

int		size_o(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		 n /= 8;
		 i++;
	}
	return (i);
}

int		conv_o(char	*str, va_list s2, int n)
{
	unsigned int	i;
	int				j;
	char			*num;

	i = va_arg(s2, unsigned int);
	j = size_o(i);
	num = ft_strnew(j);
	num[j--] = '\0';
	while (j >= 0)
	{
		num[j--] = '0' + (i % 8);
		i /= 8;
	}
	//ft_putstr(num);
	detail_o(num, str, n);
	return (0);
}	
