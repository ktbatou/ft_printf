/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:51:28 by ktbatou           #+#    #+#             */
/*   Updated: 2019/10/29 16:21:43 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_printf(char *str, ...)
{
	int i;
	int j;
	int a;
	char *s;

	i = 0;
	a = 0;
	j = 0;
	va_list ap;
	va_start (ap, str);
	s = ft_strnew(ft_size(str) + 1);
	while (str[i])
	{
		s[j] = str[i];
		if (str[i] == '%' && str[i + 1] == 's')
		{
			s(str, va_arg(ap, char*));
	
 		if (str[i] == '%' && str[i + 1] == 'c')
		{
			a = va_arg(ap, int);
			s[i] =	c(str[i], a);
			i++;
		}
		i++;
		j++;
	}
	ft_putstr(s);
	va_end(ap);
}
