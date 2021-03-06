/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:42:17 by amassnao          #+#    #+#             */
/*   Updated: 2020/03/05 18:42:22 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

void	clean(t_valeur *v, char **res)
{
	(v->num) ? free(v->num) : 0;
	(v->pre) ? free(v->pre) : 0;
	(*res) ? free(*res) : 0;
}
