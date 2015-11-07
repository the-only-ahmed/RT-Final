/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 22:12:33 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 19:58:52 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int			object_choose(t_vect3 *org, t_vect3 *dir, t_env *e, t_vars *v)
{
	int		obj;

	obj = 0;
	if (!ft_strcmp(e->types[v->i], "sphere"))
		obj = intersect_sp(e->objects[v->i], org, dir, v);
	else if (!ft_strcmp(e->types[v->i], "cylindre"))
		obj = intersect_cy(e->objects[v->i], org, dir, v);
	else if (!ft_strcmp(e->types[v->i], "cone"))
		obj = intersect_con(e->objects[v->i], org, dir, v);
	else if (!ft_strcmp(e->types[v->i], "plan"))
		obj = intersect_plan(e->objects[v->i], org, dir, &(v->t0));
	return (obj);
}

char		*fn_object_choose(t_vect3 *org, t_vect3 *dir, t_env *e, t_vars *v)
{
	char		*str;

	v->i = 0;
	v->tnear = INFINITY;
	v->sphere = NULL;
	str = NULL;
	while (e->objects[v->i])
	{
		v->t0 = INFINITY;
		v->t1 = INFINITY;
		if (object_choose(org, dir, e, v))
		{
			if (v->t0 < 0)
				v->t0 = v->t1;
			if (v->t0 < v->tnear)
			{
				v->tnear = v->t0;
				v->sphere = e->objects[v->i];
				str = ft_strdup(e->types[v->i]);
			}
		}
		v->i++;
	}
	return (str);
}

static void	fn_refraction(t_vars *v, t_vect3 *dir, t_env *e, int depth)
{
	v->facingratio = -1 * ft_dot(dir, v->nhit);
	v->fresneleffect = ft_mix(ft_pow(1 - v->facingratio, 3), 1, 0.1);
	v->refldir = sub_vect(dir, mult_vectf(v->nhit, 2.0 * ft_dot(dir, v->nhit)));
	fn_normalize(v->refldir);
	v->reflection = fn_trace(add_vect(v->phit, mult_vectf(v->nhit, v->bias)), \
							v->refldir, e, depth + 1);
	v->refraction = ft_vect_init(0, 0, 0);
	free(v->refldir);
}

void		effects(t_vars *v, t_env *e, int dep, t_vect3 *dir)
{
	if ((v->sphere->trans > 0 || v->sphere->reflection > 0) && dep < MAX_DEPTH)
	{
		fn_refraction(v, dir, e, dep);
		if (v->sphere->trans)
		{
			v->ior = 1.1;
			v->eta = (v->inside) ? v->ior : 1 / v->ior;
			v->cosi = -1 * ft_dot(v->nhit, dir);
			v->k = 1 - ft_pow(v->eta, 2) * (1 - ft_pow(v->cosi, 2));
			v->refrdir = add_vect(mult_vectf(dir, v->eta), mult_vectf(v->nhit, \
			(v->eta * v->cosi - sqrt(v->k))));
			fn_normalize(v->refrdir);
			v->refraction = fn_trace(sub_vect(v->phit, mult_vectf(v->nhit, \
									v->bias)), v->refrdir, e, dep + 1);
			free(v->refrdir);
		}
		v->surface = (mult_vect(add_vect(mult_vectf(v->reflection, \
			v->fresneleffect), mult_vectf(v->refraction, \
			((1 - v->fresneleffect) * v->sphere->trans))), \
			v->sphere->surface_c));
		free(v->refraction);
		free(v->reflection);
	}
	else
		ft_lighting(v, e);
}
