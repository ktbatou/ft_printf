/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:18:13 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/04 17:58:56 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

struct dat 
{
	char flag[10];
	void *test;
};

int     ft_printf(char *str, ...);
void    conv_c(char *s1, va_list s2);
int conv_s(char *s1, va_list s2);
int     check_num(char *str);
int  checker(char *str, va_list ap, char *s );
