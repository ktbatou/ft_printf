/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:51:28 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/04 15:11:29 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int		ft_printf(char *str, ...)
{
	int i;
	int j;
	int format;
	char *s;

	i = 0;
	j = 0;
	format = 0;
	va_list ap;
	va_start (ap, str);
	s = ft_strnew(ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			format += checker((str + i), ap, str);
			i++;
		}
		s[j] = str[i];
		ft_putchar(s[j]);
		i++;
		j++;
		format++;
	}
	va_end(ap);
	return (format);	
}
