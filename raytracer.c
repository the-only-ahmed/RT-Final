/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 02:32:45 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 20:37:40 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void		freed(t_env *e)
{
	int		i;

	free(e->cam_ray);
	i = 0;
	while (e->objects[i])
	{
		free(e->objects[i]->center);
		free(e->objects[i]->surface_c);
		free(e->objects[i]->emission_c);
		if (!ft_strcmp(e->types[i], "plan"))
			free(e->objects[i]->normal);
		free(e->objects[i]);
		free(e->types[i]);
		i++;
	}
	free(e->types);
	free(e->objects);
	i = 0;
	while (e->spot[i])
		free(e->spot[i++]);
	free(e->spot);
	free(e);
}

static void		fill_color(int x, int y, t_env *e, t_vect3 *tmp)
{
	int		color;

	color = (int)(ft_min(1.0, tmp->z) * 0xff) + \
			((int)(ft_min(1.0, tmp->y) * 0xff) << 8) + \
			((int)(ft_min(1.0, tmp->x) * 0xff) << 16);
	mlx_pixel_put(e->mlx, e->win, x, y, color);
}

static void		ray_direction_init(int x, int y, t_env *e)
{
	double		xx;
	double		yy;

	xx = (2 * ((x + 0.5) * e->invwidth) - 1) * e->angle * e->aspect_rat;
	yy = (1 - 2 * ((y + 0.5) * e->invheight)) * e->angle;
	e->raydir = ft_vect_init(xx, yy, -1.0);
	fn_normalize(e->raydir);
}

void			ft_render(t_env *e)
{
	int			x;
	int			y;
	t_vect3		*tmp;

	e->invwidth = 1.0 / ((double)(LAR));
	e->invheight = 1.0 / ((double)(LON));
	e->aspect_rat = (double)(LAR) / ((double)(LON));
	e->angle = tan(M_PI * e->fov * 0.5 / ((double)(180)));
	y = 0;
	while (y < LON)
	{
		x = 0;
		while (x < LAR)
		{
			ray_direction_init(x, y, e);
			tmp = fn_trace(e->cam_ray, e->raydir, e, 0);
			fill_color(x, y, e, tmp);
			free(e->raydir);
			free(tmp);
			x++;
		}
		y++;
	}
	freed(e);
}
