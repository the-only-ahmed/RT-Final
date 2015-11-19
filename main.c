/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 17:21:06 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/19 21:56:43 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			init_main(t_data *dat)
{
	if ((dat->mlx_ptr = mlx_init()) == NULL)
		return (-1);
	if ((dat->mlx_win = mlx_new_window(dat->mlx_ptr, IMG_H, IMG_W, "RT")) \
			== NULL)
		return (-1);
	dat->img = mlx_new_image(dat->mlx_ptr, IMG_H, IMG_W);
	dat->str = mlx_get_data_addr(dat->img, &(dat->bpp), &(dat->sl), &(dat->nd));
	dat->quality = set_quality();
	dat->pos = 0;
	return (0);
}

t_vec		rt_rayvec(void)
{
	t_vec	vec;
	double	dist;

	dist = sqrt(vec.x * vec.x + vec.y * vec.y + vec.w * vec.w);
	vec.x = vec.x / dist;
	vec.y = vec.y / dist;
	vec.w = vec.w / dist;
	return (vec);
}

void		add_file(t_data *e, char *file)
{
	t_files *tmp;
	t_files *ptr;

	tmp = (t_files*)malloc(sizeof(t_files));
	tmp->name = ft_strdup(file);
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->selected = FALSE;
	if (e->file == NULL)
	{
		tmp->selected = TRUE;
		e->file = tmp;
	}
	else
	{
		ptr = e->file;
		while (ptr->next)
			ptr = ptr->next;
		tmp->prev = ptr;
		ptr->next = tmp;
	}
}

t_bool		get_files(t_data *e)
{
	DIR				*dir;
	struct dirent	*s_dir;

	dir = opendir("./samples");
	if (dir == NULL)
		return (FALSE);
	e->file = NULL;
	while ((s_dir = readdir(dir)))
	{
		if (s_dir->d_name[0] != '.')
			add_file(e, s_dir->d_name);
	}
	return (TRUE);
}

int			main(void)
{
	t_data		data;

	init_main(&data);
	if (get_files(&data) == FALSE)
		return (-1);
	mlx_key_hook(data.mlx_win, ft_key_hook, &data);
	mlx_expose_hook(data.mlx_win, menu_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
