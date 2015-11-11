/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 21:09:28 by jyim              #+#    #+#             */
/*   Updated: 2014/01/26 22:22:16 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char		i;

	i = c;
	while (*s != i)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}