/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intialisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:44:20 by ktbatou           #+#    #+#             */
/*   Updated: 2019/12/25 11:49:55 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	intial(t_detail *d, t_valeur *v)
{
	d->minus = 0;
	d->hash = 0;
	d->point = 0;
	d->plus = 0;
	d->zero = 0;
	d->space = 0;
	d->h = 0;
	d->l = 0;
	v->f = 0;
	v->i = 0;
	v->j = 0;
	v->a = 0;
	v->n = 0;
	v->flag = 0;
	v->num = 0;
	v->pre = 0;
	v->h = 0;
	v->l = 0;
	v->hh = 0;
	v->ll = 0;
}

void	unsigned_intial(t_detail *d, t_unsigned_v *v)
{
	d->minus = 0;
	d->hash = 0;
	d->point = 0;
	d->plus = 0;
	d->zero = 0;
	d->space = 0;
	d->h = 0;
	d->l = 0;
	v->signe = 0;
	v->i = 0;
	v->h = 0;
	v->l = 0;
	v->hh = 0;
	v->ll = 0;
}
