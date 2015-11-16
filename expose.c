/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 18:52:36 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/16 18:59:22 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			ft_expose_hook(t_data *e)
{
	mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img, 0, 0);
	return (0);
}

void		printselected(t_data *e, t_files *file)
{
	t_overview	over;
	char		*path;

	path = ft_strjoin("./samples/", file->name);
	over = ft_parser(path);
	render(e, over);
	ft_expose_hook(e);
	mlx_expose_hook(e->mlx_win, ft_expose_hook, e);
	free(path);
}

int			menu_hook(t_data *e)
{
	t_files	*ptr;
	int		color;
	int		i;

	i = 0;
	ptr = e->file;
	mlx_clear_window(e->mlx_ptr, e->mlx_win);
	while (ptr)
	{
		color = (ptr->selected) ? 0xFF0000 : 0xFFFFFF;
		mlx_string_put(e->mlx_ptr, e->mlx_win, 400, 600 + i, color, ptr->name);
		ptr = ptr->next;
		i += 100;
	}
	return (0);
}
