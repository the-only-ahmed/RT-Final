/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:05:35 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/26 19:53:47 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_debspace_pos(char const *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	return (i);
}

static int		ft_endspace_pos(char const *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*ch;
	int		i;
	int		j;
	int		length;

	i = ft_debspace_pos(s);
	j = 0;
	if (i == 0 && ft_endspace_pos(s) == ((int)ft_strlen(s) - 1))
		return ((char *)s);
	length = ft_endspace_pos(s) - i;
	ch = (char*)malloc(sizeof(char) * (length + 1));
	if (ch == NULL)
		return (NULL);
	while (i <= ft_endspace_pos(s))
	{
		ch[j] = s[i];
		j++;
		i++;
	}
	ch[j] = '\0';
	return (ch);
}
