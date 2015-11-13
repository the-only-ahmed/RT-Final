/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 18:33:03 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/13 18:36:26 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			ft_interconex(t_vec rayorg, t_vec raydir, t_obj *obj)
{
	t_cylinder cone;

	cone.a = ft_dotx(raydir, raydir) - obj->radius * (raydir.x * raydir.x);
	cone.b = ft_dotx(mul_vec(sub_vec(rayorg, obj->pos), 2.0), raydir) \
			- obj->radius * (raydir.x * raydir.x);
	cone.c = ft_dotx(obj->pos, obj->pos) + ft_dotx(rayorg, rayorg) - (2.0 * \
			ft_dotx(rayorg, obj->pos)) - obj->radius * (raydir.x * raydir.x);
	cone.delt = pow(cone.b, 2) - (4.0 * cone.a * cone.c);
	if (cone.delt >= 0)
	{
		cone.a1 = ((-1.0 * cone.b) - sqrt(cone.delt)) / (2.0 * cone.a);
		cone.b1 = ((-1.0 * cone.b) + sqrt(cone.delt)) / (2.0 * cone.a);
		if (cone.b1 > cone.a1)
			cone.ret = cone.a1;
		else
			cone.ret = cone.b1;
		if (cone.a1 <= 0 && cone.b1 <= 0)
			return (0);
	}
	else
		return (0);
	return (cone.ret);
}

int			ft_interconey(t_vec rayorg, t_vec raydir, t_obj *obj)
{
	t_cylinder cone;

	cone.a = ft_doty(raydir, raydir) - obj->radius * (raydir.y * raydir.y);
	cone.b = ft_doty(mul_vec(sub_vec(rayorg, obj->pos), 2.0), raydir) \
			- obj->radius * (raydir.y * raydir.y);
	cone.c = ft_doty(obj->pos, obj->pos) + ft_doty(rayorg, rayorg) - (2.0 * \
			ft_doty(rayorg, obj->pos)) - obj->radius * (raydir.y * raydir.y);
	cone.delt = pow(cone.b, 2) - (4.0 * cone.a * cone.c);
	if (cone.delt >= 0)
	{
		cone.a1 = ((-1.0 * cone.b) - sqrt(cone.delt)) / (2.0 * cone.a);
		cone.b1 = ((-1.0 * cone.b) + sqrt(cone.delt)) / (2.0 * cone.a);
		if (cone.b1 > cone.a1)
			cone.ret = cone.a1;
		else
			cone.ret = cone.b1;
		if (cone.a1 <= 0 && cone.b1 <= 0)
			return (0);
	}
	else
		return (0);
	return (cone.ret);
}

int			ft_interconew(t_vec rayorg, t_vec raydir, t_obj *obj)
{
	t_cylinder cone;

	cone.a = ft_dotw(raydir, raydir) - obj->radius * (raydir.w * raydir.w);
	cone.b = ft_dotw(mul_vec(sub_vec(rayorg, obj->pos), 2.0), raydir) \
			- obj->radius * (raydir.w * raydir.w);
	cone.c = ft_dotw(obj->pos, obj->pos) + ft_dotw(rayorg, rayorg) - (2.0 * \
			ft_dotw(rayorg, obj->pos)) - obj->radius * (raydir.w * raydir.w);
	cone.delt = pow(cone.b, 2) - (4.0 * cone.a * cone.c);
	if (cone.delt >= 0)
	{
		cone.a1 = ((-1.0 * cone.b) - sqrt(cone.delt)) / (2.0 * cone.a);
		cone.b1 = ((-1.0 * cone.b) + sqrt(cone.delt)) / (2.0 * cone.a);
		if (cone.b1 > cone.a1)
			cone.ret = cone.a1;
		else
			cone.ret = cone.b1;
		if (cone.a1 <= 0 && cone.b1 <= 0)
			return (0);
	}
	else
		return (0);
	return (cone.ret);
}

int			ft_intercone(t_vec rayorg, t_vec raydir, t_obj *obj)
{
	if (obj->axe == 'w')
		return (ft_interconew(rayorg, raydir, obj));
	if (obj->axe == 'x')
		return (ft_interconex(rayorg, raydir, obj));
	if (obj->axe == 'y')
		return (ft_interconey(rayorg, raydir, obj));
	return (0);
}
