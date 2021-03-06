/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:03:08 by jyim              #+#    #+#             */
/*   Updated: 2014/05/21 15:14:11 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	int			i;
	char		*ss1;
	const char	*ss2;

	i = 0;
	ss1 = s1;
	ss2 = s2;
	while (n > 0)
	{
		ss1[i] = ss2[i];
		n--;
		i++;
	}
	return (ss1);
}
