/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 00:22:20 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/02/16 23:30:51 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*tmp;

	tmp = malloc (sizeof(t_list));
	if (tmp)
	{
		if (content == NULL)
		{
			tmp->content_size = 0;
			tmp->content = NULL;
		}
		else
		{
			tmp->content_size = content_size;
			ft_memcpy(tmp->content, content, content_size);
		}
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}
