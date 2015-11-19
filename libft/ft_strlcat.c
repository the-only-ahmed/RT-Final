/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:06:47 by jyim              #+#    #+#             */
/*   Updated: 2015/11/19 21:05:35 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*src2;
	size_t		size2;
	size_t		len;
	char		*dst2;

	len = size;
	dst2 = dst;
	src2 = src;
	size2 = size;
	while (*dst2 != '\0' && size2-- > 0)
		dst2++;
	len = dst2 - dst;
	size2 = size - len;
	if (size2 == 0)
		return (len + ft_strlen(src2));
	return (0);
}
