/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 18:14:05 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/13 18:20:42 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		hit_cylx(t_vec raydir, t_vec rayorg, t_obj *obj)
{
	t_cylinder cyl;

	cyl.a = ft_dotx(raydir, raydir);
	cyl.b = ft_dotx(mul_vec(sub_vec(rayorg, obj->pos), 2.0), raydir);
	cyl.c = ft_dotx(obj->pos, obj->pos) + ft_dotx(rayorg, rayorg) - (2.0 * \
			ft_dotx(rayorg, obj->pos)) - (obj->radius);
	cyl.delt = pow(cyl.b, 2) - (4.0 * cyl.a * cyl.c);
	if (cyl.delt >= 0)
	{
		cyl.a1 = ((-1.0 * cyl.b) - sqrt(cyl.delt)) / (2.0 * cyl.a);
		cyl.b1 = ((-1.0 * cyl.b) + sqrt(cyl.delt)) / (2.0 * cyl.a);
		if (cyl.b1 > cyl.a1)
			cyl.ret = cyl.a1;
		else
			cyl.ret = cyl.b1;
		if (cyl.a1 <= 0 && cyl.b1 <= 0)
			return (0);
	}
	else
		return (0);
	return (cyl.ret);
}

double		hit_cylw(t_vec raydir, t_vec rayorg, t_obj *obj)
{
	t_cylinder cyl;

	cyl.a = ft_dotw(raydir, raydir);
	cyl.b = ft_dotw(mul_vec(sub_vec(rayorg, obj->pos), 2.0), raydir);
	cyl.c = ft_dotw(obj->pos, obj->pos) + ft_dotw(rayorg, rayorg) - (2.0 * \
			ft_dotw(rayorg, obj->pos)) - obj->radius;
	cyl.delt = pow(cyl.b, 2) - (4.0 * cyl.a * cyl.c);
	if (cyl.delt >= 0)
	{
		cyl.a1 = ((-1.0 * cyl.b) - sqrt(cyl.delt)) / (2.0 * cyl.a);
		cyl.b1 = ((-1.0 * cyl.b) + sqrt(cyl.delt)) / (2.0 * cyl.a);
		if (cyl.b1 > cyl.a1)
			cyl.ret = cyl.a1;
		else
			cyl.ret = cyl.b1;
		if (cyl.a1 <= 0 && cyl.b1 <= 0)
			return (0);
	}
	else
		return (0);
	return (cyl.ret);
}

double		hit_cyly(t_vec raydir, t_vec rayorg, t_obj *obj)
{
	t_cylinder cyl;

	cyl.a = ft_doty(raydir, raydir);
	cyl.b = ft_doty(mul_vec(sub_vec(rayorg, obj->pos), 2.0), raydir);
	cyl.c = ft_doty(obj->pos, obj->pos) + ft_doty(rayorg, rayorg) - (2.0 * \
			ft_doty(rayorg, obj->pos)) - obj->radius;
	cyl.delt = pow(cyl.b, 2) - (4.0 * cyl.a * cyl.c);
	if (cyl.delt >= 0)
	{
		cyl.a1 = ((-1.0 * cyl.b) - sqrt(cyl.delt)) / (2.0 * cyl.a);
		cyl.b1 = ((-1.0 * cyl.b) + sqrt(cyl.delt)) / (2.0 * cyl.a);
		if (cyl.b1 > cyl.a1)
			cyl.ret = cyl.a1;
		else
			cyl.ret = cyl.b1;
		if (cyl.a1 <= 0 && cyl.b1 <= 0)
			return (0);
	}
	else
		return (0);
	return (cyl.ret);
}

double		hit_cyl(t_vec dir, t_vec o, t_obj *obj)
{
	if (obj->axe == 'x')
		return (hit_cylx(dir, o, obj));
	else if (obj->axe == 'y')
		return (hit_cyly(dir, o, obj));
	else
		return (hit_cylw(dir, o, obj));
	return (-1);
}
