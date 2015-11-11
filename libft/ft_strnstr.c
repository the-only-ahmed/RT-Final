/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:59:15 by jyim              #+#    #+#             */
/*   Updated: 2013/11/24 19:47:38 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (n < ft_strlen(s2))
		return (NULL);
	if (!s2)
		return (NULL);
	if (strlen(s1) < 1)
		return ((char *)s2);
  while(*s1 && n > 0)
	   {
	      if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
            return (char *)s1;
		    s1++;
				n--;
				if (n < ft_strlen(s2))
					break ;
	   }
    return NULL;
}
