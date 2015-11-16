/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 18:54:39 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/16 19:05:21 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool		arrow_keys(int key_code, t_data *e, t_files *ptr)
{
	if (key_code == UP)
	{
		if (ptr->prev)
		{
			ptr->selected = FALSE;
			ptr->prev->selected = TRUE;
			menu_hook(e);
		}
	}
	else if (key_code == DOWN)
	{
		if (ptr->next)
		{
			ptr->selected = FALSE;
			ptr->next->selected = TRUE;
			menu_hook(e);
		}
	}
	else
		return (FALSE);
	return (TRUE);
}

int			ft_key_hook(int key_code, t_data *e)
{
	t_files	*ptr;

	ptr = e->file;
	while (ptr)
	{
		if (ptr->selected == TRUE)
			break ;
		ptr = ptr->next;
	}
	if (arrow_keys(key_code, e, ptr) == TRUE)
		return (0);
	else if (key_code == ENTER)
	{
		mlx_clear_window(e->mlx_ptr, e->mlx_win);
		printselected(e, ptr);
	}
	else if (key_code == ESC)
		exit(0);
	return (0);
}
