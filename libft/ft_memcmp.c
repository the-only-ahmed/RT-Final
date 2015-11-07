/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:03:17 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/11/26 10:57:27 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	const unsigned char	*str2;

	str = s1;
	str2 = s2;
	i = 0;
	while (i < n && str[i] == str2[i])
		i++;
	if (i == n)
		return (0);
	else
		return (str[i] - str2[i]);
}
