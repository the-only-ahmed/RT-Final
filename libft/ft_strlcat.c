/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:42:43 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/11/23 04:04:09 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	x;
	int		i;

	a = ft_strlen(dst);
	b = ft_strlen(src);
	i = 0;
	if (size >= a)
	{
		x = b + a;
		while (a < (size - 1))
		{
			dst[a] = src[i];
			a++;
			i++;
		}
		dst[a] = '\0';
		return (x);
	}
	else
		return (size + b);
}
