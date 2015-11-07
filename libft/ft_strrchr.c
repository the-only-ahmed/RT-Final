/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:00:53 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/26 19:50:44 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		pos;

	i = 0;
	pos = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			pos = i;
		i++;
	}
	if (s[i] == c)
		pos = i;
	if (pos != -1)
		return ((char*)&s[pos]);
	else
		return (NULL);
}
