/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 17:21:06 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/13 18:39:50 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			ft_expose_hook(t_data *e)
{
	mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img, 0, 0);
	return (0);
}

int			init_main(t_data *dat)
{
	if ((dat->mlx_ptr = mlx_init()) == NULL)
		return (-1);
	if ((dat->mlx_win = mlx_new_window(dat->mlx_ptr, IMG_H, IMG_W, "RT")) \
			== NULL)
		return (-1);
	dat->img = mlx_new_image(dat->mlx_ptr, IMG_H, IMG_W);
	dat->str = mlx_get_data_addr(dat->img, &(dat->bpp), &(dat->sl), &(dat->nd));
	return (0);
}

t_vec		rt_rayvec(int x, int y)
{
	t_vec	vec;
	double	dist;

	dist = sqrt(vec.x * vec.x + vec.y * vec.y + vec.w * vec.w);
	vec.x = vec.x / dist;
	vec.y = vec.y / dist;
	vec.w = vec.w / dist;
	return (vec);
}

void		test(t_data *data)
{
	int i;

	i = 0;
	while (i < IMG_W)
	{
		image_pixel_put(data, i, 0, creatergb(156, 88, 88));
		i++;
	}
}

int			main(int ac, char **av)
{
	t_data		data;
	t_overview	over;

	(void)ac;
	init_main(&data);
	over = ft_parser(av[1]);
	render(&data, over);
	mlx_expose_hook(data.mlx_win, ft_expose_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
