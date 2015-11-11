/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 21:34:08 by jyim              #+#    #+#             */
/*   Updated: 2014/01/12 01:49:45 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
	if (!s2)
		return (NULL);
	if (strlen(s1) < 1)
		return ((char *)s2);
    while(*s1)
    {
        if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
            return (char *)s1;
        s1++;
    }
    return NULL;
}
