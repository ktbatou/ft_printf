/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_taille.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:30:31 by ktbatou           #+#    #+#             */
/*   Updated: 2019/11/04 12:27:46 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_num(char *str)
{
	int a;

	a = 0;
	//if (*(++str) >= '0' && *(str) <= '9')
//	{ 
//		printf("11111111111111");
//		//a = atoi(str);
//		//while (a-- >= 0)	
//		//	ft_putchar(' ');
//	}
//	else
//	{
		a = atoi(str);
	while (a-- >= 0)
		ft_putchar(' ');
//	}
	return (0);
}
