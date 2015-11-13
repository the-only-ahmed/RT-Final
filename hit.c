/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 18:38:14 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/13 18:43:53 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		hit_sphere(t_vec dir, t_vec o, t_obj *obj)
{
	double	equation;
	double	a;
	double	b;
	t_vec	ret;

	ret.x = (dir.x * dir.x) + (dir.y * dir.y) + (dir.w * dir.w);
	ret.y = 2 * (dir.x * (o.x - obj->pos.x) + dir.y * (o.y - obj->pos.y)
		+ dir.w * (o.w - obj->pos.w));
	ret.w = ((o.x - obj->pos.x) * (o.x - obj->pos.x) + (o.y - obj->pos.y)
		* (o.y - obj->pos.y) + (o.w - obj->pos.w) * (o.w - obj->pos.w))
		- (obj->radius * obj->radius);
	equation = ((ret.y) * (ret.y)) - 4 * ret.x * ret.w;
	if (equation < 0)
		return (-1);
	if (equation > 0)
	{
		a = (-(ret.y) + sqrtf(equation)) / (2 * ret.x);
		b = (-(ret.y) - sqrtf(equation)) / (2 * ret.x);
		if (a < 0 && b < 0)
			return (0);
		return (a = a < b ? a : b);
	}
	a = (-(ret.y) + sqrtf(equation)) / (2 * ret.x);
	return ((a < 0) ? 0 : a);
}

double		hit_plane(t_vec dir, t_vec o, t_obj *obj)
{
	double	d;
	double	dist;

	d = DOT(obj->pos, dir);
	if (d != 0)
	{
		dist = -(DOT(obj->pos, o) + obj->radius) / d;
		if (dist > 0)
			return (dist);
	}
	return (-1);
}
