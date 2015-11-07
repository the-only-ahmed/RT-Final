/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 03:31:05 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/26 19:34:03 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_vect3	*fn_trace2(t_vars *v, t_env *e, int depth, t_vect3 *dir)
{
	fn_normalize(v->nhit);
	v->bias = 1e-4;
	v->inside = 0;
	if (ft_dot(dir, v->nhit) > 0)
	{
		v->nhit = mult_vectf(v->nhit, -1.0);
		v->inside = 1;
	}
	effects(v, e, depth, dir);
	if (!depth)
		free(v->tmp);
	free(v->nhit);
	free(v->phit);
	free(v->surface);
	return (add_vect(v->surface, v->sphere->emission_c));
}

t_vect3			*fn_trace(t_vect3 *rayorig, t_vect3 *dir, t_env *e, int depth)
{
	char		*str;
	t_vars		*v;

	v = (t_vars*)malloc(sizeof(t_vars));
	v->depth = depth;
	if (!(str = fn_object_choose(rayorig, dir, e, v)))
	{
		v->sphere = fn_spoting(rayorig, dir, e, &(v->tnear));
		if (v->sphere)
			str = ft_strdup("spot");
	}
	if (!str)
	{
		v->tmp = ft_vect_init(0, 0, 0);
		return (v->tmp);
	}
	v->surface = ft_vect_init(0, 0, 0);
	v->phit = object_point(str, v, rayorig, dir);
	v->nhit = object_normal(str, v);
	free(str);
	return (fn_trace2(v, e, depth, dir));
}
