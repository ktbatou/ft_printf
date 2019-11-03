/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:51:28 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/03 18:41:42 by ktbatou          ###   ########.fr       */
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
			printf("%c\n", str + i);
			//checker((str + i), ap, str);
			/*if (str[i] >= '0' && str[i] <= '9')
			{
				check_num(str + i);
				i++;
			}
			if (str[i] == '%')
			{
				ft_putchar('%');
				i++;
			}
			if (str[i] == 's')
			{
				i += 1;
				format += conv_s(str, ap);
			}
			if (str[i] == 'c')
			{
				i += 1;
				conv_c(str, ap);
				format++;
			}
			s[j] = str[i];
		}*/
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
