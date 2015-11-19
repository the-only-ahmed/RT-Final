/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 18:54:39 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/19 20:59:47 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool		arrow_keys(int key_code, t_data *e, t_files *ptr, int (*f)(t_data*))
{
	if (key_code == UP)
	{
		if (ptr->prev)
		{
			ptr->selected = FALSE;
			ptr->prev->selected = TRUE;
			f(e);
		}
	}
	else if (key_code == DOWN)
	{
		if (ptr->next)
		{
			ptr->selected = FALSE;
			ptr->next->selected = TRUE;
			f(e);
		}
	}
	else
		return (FALSE);
	return (TRUE);
}

void		enter_key(t_data *e, t_files *ptr)
{
	e->pos = (e->pos > 1) ? 0 : e->pos + 1;
	mlx_clear_window(e->mlx_ptr, e->mlx_win);
	if (e->pos == 1)
	{
		e->path = ft_strdup(ptr->name);
		quality_hook(e);
		mlx_expose_hook(e->mlx_win, quality_hook, e);
	}
	else
		printselected(e, ptr->quality);
}

int			ft_key_hook(int key_code, t_data *e)
{
	t_files	*ptr;
	void	*fun_ptr;

	ptr = e->file;
	fun_ptr = menu_hook;
	if (e->pos == 1)
	{
		ptr = e->quality;
		fun_ptr = quality_hook;
	}
	while (ptr)
	{
		if (ptr->selected == TRUE)
			break ;
		ptr = ptr->next;
	}
	if (arrow_keys(key_code, e, ptr, fun_ptr) == TRUE)
		return (0);
	else if (key_code == ENTER)
		enter_key(e, ptr);
	else if (key_code == ESC)
		exit(0);
	return (0);
}

t_files		*add_quality(char *quality, int q)
{
	t_files *tmp;

	tmp = (t_files*)malloc(sizeof(t_files));
	tmp->name = ft_strdup(quality);
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->selected = FALSE;
	tmp->quality = q;
	return (tmp);
}

t_files		*set_quality(void)
{
	t_files	*tmp;

	tmp = add_quality("144p", 4);
	tmp->selected = TRUE;
	tmp->next = add_quality("360p", 3);
	tmp->next->prev = tmp;
	tmp->next->next = add_quality("720p", 2);
	tmp->next->next->prev = tmp->next;
	tmp->next->next->next = add_quality("1080p", 1);
	tmp->next->next->next->prev = tmp->next->next;
	return (tmp);
}
