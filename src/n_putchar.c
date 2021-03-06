/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_putchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:59:46 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/12 14:44:35 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	n_putchar(char c, t_valeur *v)
{
	v->rest++;
	write(1, &c, 1);
}
