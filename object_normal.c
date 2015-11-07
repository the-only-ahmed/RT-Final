/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 21:12:02 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/26 21:04:13 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_vect3		*fn_cyl(t_vars *v, t_vect3 *rayorig, t_vect3 *dir)
{
	t_vect3		*phit;

	if (v->sphere->axe == 'z')
		phit = ft_vect_init(rayorig->x + (dir->x * v->tnear), \
				rayorig->y + (dir->y * v->tnear), 0);
	else if (v->sphere->axe == 'y')
		phit = ft_vect_init(rayorig->x + (dir->x * v->tnear), 0, \
				rayorig->z + (dir->z * v->tnear));
	else
		phit = ft_vect_init(0, rayorig->y + (dir->y * v->tnear), \
				rayorig->z + (dir->z * v->tnear));
	return (phit);
}

t_vect3				*fn_con(t_vars *v)
{
	t_vect3		*nhit;

	if (v->sphere->axe == 'z')
		nhit = ft_vect_init(v->phit->x - v->sphere->center->x, \
		v->phit->y - v->sphere->center->y, (v->sphere->center->z - \
		v->phit->z) * tan(v->sphere->radius_2));
	else if (v->sphere->axe == 'y')
		nhit = ft_vect_init(v->phit->x - v->sphere->center->x, \
		(v->sphere->center->y - v->phit->y) * \
		tan(v->sphere->radius_2), v->phit->z - v->sphere->center->z);
	else
		nhit = ft_vect_init((v->sphere->center->x - v->phit->x) * \
		tan(v->sphere->radius_2), v->phit->y - v->sphere->center->y, \
		v->phit->z - v->sphere->center->z);
	return (nhit);
}

t_vect3				*object_point(char *str, t_vars *v, t_vect3 *rayorig, \
		t_vect3 *dir)
{
	t_vect3		*phit;

	if (!ft_strcmp(str, "cylindre"))
		return (fn_cyl(v, rayorig, dir));
	else if (!ft_strcmp(str, "cone"))
	{
		if (v->sphere->axe == 'z')
			phit = ft_vect_init(rayorig->x + (dir->x * v->tnear), rayorig->y + \
					(dir->y * v->tnear), rayorig->z + (dir->z * v->tnear));
		else if (v->sphere->axe == 'y')
			phit = ft_vect_init(rayorig->x + (dir->x * v->tnear), rayorig->y + \
					(dir->y * v->tnear), rayorig->z + (dir->z * v->tnear));
		else
			phit = ft_vect_init(rayorig->x + (dir->x * v->tnear), rayorig->y + \
					(dir->y * v->tnear), rayorig->z + (dir->z * v->tnear));
	}
	else
		phit = add_vect(rayorig, mult_vectf(dir, v->tnear));
	return (phit);
}

t_vect3				*object_normal(char *str, t_vars *v)
{
	t_vect3		*nhit;

	if (!ft_strcmp(str, "cylindre") || !ft_strcmp(str, "cone"))
	{
		if (v->sphere->axe == 'z')
			nhit = ft_vect_init(v->phit->x - v->sphere->center->x, \
								v->phit->y - v->sphere->center->y, 0);
		else if (v->sphere->axe == 'y')
			nhit = ft_vect_init(v->phit->x - v->sphere->center->x, 0, \
								v->phit->z - v->sphere->center->z);
		else
			nhit = ft_vect_init(0, v->phit->y - v->sphere->center->y, \
								v->phit->z - v->sphere->center->z);
	}
	else
		nhit = sub_vect(v->phit, v->sphere->center);
	return (nhit);
}
