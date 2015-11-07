/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:55:29 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/11/26 10:57:39 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*str;
	const char	*str2;

	i = 0;
	str = s1;
	str2 = s2;
	while (i < n)
	{
		str[i] = str2[i];
		i++;
	}
	return (str);
}
