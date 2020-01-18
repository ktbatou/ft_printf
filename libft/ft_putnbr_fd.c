/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:00:55 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/09 22:08:01 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char *s;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		s = ft_itoa(n);
		ft_putstr_fd(s, fd);
	}
}
