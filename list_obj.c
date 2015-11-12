/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 20:03:24 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/12 20:04:09 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj	*add_obj(t_obj *l, t_obj *to_add)
{
	t_obj *tmp;

	tmp = l;
	if (!tmp)
		return (to_add);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = to_add;
	return (l);
}
