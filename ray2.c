/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 18:15:16 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/16 12:51:37 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec			init_vec(void)
{
	t_vec vec;

	vec.x = 0;
	vec.y = 0;
	vec.w = 0;
	return (vec);
}

t_vec			set_vec(double x, double y, double z)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.w = z;
	return (vec);
}

t_vec			set_nvec(t_obj *ret, t_vec dir, t_vec o, double ret2)
{
	if (ret->axe == 'x')
		return (set_vec(0, o.y + (dir.y * ret2), dir.w * ret2));
	else if (ret->axe == 'w')
		return (set_vec(o.x + (dir.x * ret2), o.y + (dir.y * ret2), 0));
	return (set_vec(o.x + (dir.x * ret2), 0, o.w + (dir.w * ret2)));
}

void			return_i(t_raytracer *ray, t_vec dir, t_vec o)
{
	if (ray->tmp->type == SPHERE)
		ray->i = hit_sphere(dir, o, ray->tmp);
	else if (ray->tmp->type == PLAN)
		ray->i = hit_plane(dir, o, ray->tmp);
	else if (ray->tmp->type == CYLINDRE)
		ray->i = hit_cyl(dir, o, ray->tmp);
	else if (ray->tmp->type == CONE)
		ray->i = ft_intercone(o, dir, ray->tmp);
}

t_raytracer		*init_ray(t_obj *l)
{
	t_raytracer *ray;

	ray = (t_raytracer*)malloc(sizeof(t_raytracer));
	ray->color = init_vec();
	ray->ret = NULL;
	ray->i = -1;
	ray->in = -1;
	ray->ret2 = 0;
	ray->tmp = l;
	return (ray);
}
