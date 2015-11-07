/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 16:05:09 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/02/16 21:19:26 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

char	*delete_spaces(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == ' ' && (i == 0 || i == (int)ft_strlen(str) - 1)) \
			|| (str[i] == c && str[i + 1] == c))
		{
			j = i;
			while (str[j] != '\0')
			{
				str[j] = str[j + 1];
				j++;
			}
			i--;
		}
		i++;
	}
	return (str);
}
