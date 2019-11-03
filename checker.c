/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:13:26 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/03 18:40:30 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int  checker(char *str, va_list ap, char *s )
{
	int format;
	
	format = 0;
	
	//printf(" ========> %c\n",str);
	/*if (*str >= '0' && *str <= '9')
	{
		check_num(*str);
		*str++;
	}
	if (*str == '%')
	{
		ft_putchar('%');
		*str++;
	}
	if (*str == 's')
		format += conv_s(s, ap);
		*str++;
	}
	if (*str == 'c')
	{
		conv_c(s, ap);
		format++;
	}*/
	return (format);
}
