/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 20:45:31 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/26 21:03:34 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void		init_cone(t_sp *cone, t_con_var *var, t_vect3 *dir, t_vect3 \
							*rayorig)
{
	if (cone->axe == 'x')
	{
		var->ray = dir->x;
		var->org = rayorig->x;
		var->con = cone->center->x;
	}
	else if (cone->axe == 'y')
	{
		var->ray = dir->y;
		var->org = rayorig->y;
		var->con = cone->center->y;
	}
	else
	{
		var->ray = dir->z;
		var->org = rayorig->z;
		var->con = cone->center->z;
	}
}

int				intersect_con(t_sp *cone, t_vect3 *rayorig, t_vect3 *dir, \
		t_vars *v)
{
	t_con_var	var;

	init_cone(cone, &var, dir, rayorig);
	var.a = ft_dot_inf(dir, dir, cone->axe) - ft_pow(var.ray, 2);
	var.b = 2 * ((ft_dot_inf(dir, rayorig, cone->axe) - (var.ray * var.org)) \
				- (ft_dot_inf(dir, cone->center, 'x') - (var.ray * var.con)));
	var.c = (ft_dot_inf(cone->center, cone->center, cone->axe) - \
				ft_pow(var.con, 2)) + (ft_dot_inf(rayorig, rayorig, 'x') - \
				ft_pow(var.org, 2)) - (2 * \
				ft_dot_inf(cone->center, rayorig, 'x') - (var.con * var.org));
	var.delta = ft_disc(var.a, var.b, var.c);
	if (var.delta < 0)
		return (0);
	v->t0 = (-var.b - sqrt(var.delta)) / (2 * var.a);
	v->t1 = (-var.b + sqrt(var.delta)) / (2 * var.a);
	if (v->t0 <= 0 && v->t1 <= 0)
		return (0);
	return (1);
}
