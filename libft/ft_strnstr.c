/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:08:39 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/26 19:50:32 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[j])
			j++;
		else if (!(s1[i - 1] != s2[j] && s1[i] == s1[i - 1]))
			j = 0;
		if (s2[j] == '\0')
			return ((char*)&s1[i - j + 1]);
		i++;
	}
	return (NULL);
}
