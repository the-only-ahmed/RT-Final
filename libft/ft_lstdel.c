/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:29:37 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/11/26 10:56:48 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*temp;

	tmp = *alst;
	while (tmp->next)
	{
		temp = tmp;
		tmp = tmp->next;
		del(temp, temp->content_size);
		temp = NULL;
	}
	del(*alst, (*alst)->content_size);
	*alst = NULL;
}
