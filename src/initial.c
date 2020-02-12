/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:44:20 by ktbatou           #+#    #+#             */
/*   Updated: 2020/02/12 14:38:58 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	intial(t_detail *d, t_valeur *v)
{
	if (d != NULL)
	{
		d->minus = 0;
		d->hash = 0;
		d->point = 0;
		d->plus = 0;
		d->zero = 0;
		d->space = 0;
		d->h = 0;
		d->l = 0;
	}
	if (v != NULL)
	{
		initial_valeur(v);
	}
}

void	initial_valeur(t_valeur *v)
{
	v->f = 0;
	v->i = 0;
	v->j = 0;
	v->a = 0;
	v->n = 0;
	v->rest = 0;
	v->flag = 0;
	v->num = 0;
	v->pre = 0;
	v->sum = 0;
	v->h = 0;
	v->l = 0;
	v->hh = 0;
	v->ll = 0;
	v->signe = 0;
}
