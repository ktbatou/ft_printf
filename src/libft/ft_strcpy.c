/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:10:24 by ktbatou           #+#    #+#             */
/*   Updated: 2019/04/06 18:55:31 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}