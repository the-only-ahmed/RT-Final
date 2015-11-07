/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:16:18 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/02/16 23:31:53 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*dest_temp;
	const char		*src_temp = src;
	size_t			count;

	dest_temp = dest;
	count = 0;
	while (n != 0)
	{
		dest_temp[count] = src_temp[count];
		if (dest_temp[count] == c)
		{
			count++;
			return (dest_temp + count);
		}
		dest_temp[count] = src_temp[count];
		count++;
		n--;
	}
	return (NULL);
}
