/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 00:40:32 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/11/25 10:26:57 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = lst;
	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp == NULL)
		return (tmp);
	while (tmp2->next != NULL)
	{
		tmp = f(tmp2);
		tmp2 = tmp2->next;
		tmp->next = f(tmp2->next);
		tmp = tmp->next;
	}
	return (tmp);
}
