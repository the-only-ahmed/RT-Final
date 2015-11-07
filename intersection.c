/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 23:13:30 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/26 19:25:17 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int		intersect_sp(t_sp *sphere, t_vect3 *rayorig, t_vect3 *dir, t_vars *v)
{
	double		tca;
	double		thc;
	double		d2;
	t_vect3		*l;

	l = sub_vect(sphere->center, rayorig);
	tca = ft_dot(dir, l);
	if (tca < 0)
		return (0);
	d2 = ft_dot(l, l) - ft_pow(tca, 2);
	if (d2 > sphere->radius_2)
		return (0);
	thc = sqrt(sphere->radius_2 - d2);
	if (&(v->t0) && &(v->t1))
	{
		v->t0 = tca - thc;
		v->t1 = tca + thc;
	}
	free(l);
	return (1);
}

int		intersect_cy(t_sp *c, t_vect3 *rayorig, t_vect3 *dir, t_vars *v)
{
	double		a;
	double		b;
	double		d;
	double		delta;

	a = ft_dot_inf(dir, dir, c->axe);
	b = ft_dot_inf(mult_vectf(sub_vect(rayorig, c->center), 2.0), dir, c->axe);
	d = ft_dot_inf(c->center, c->center, c->axe) + ft_dot_inf(rayorig, rayorig,
		c->axe) - (2.0 * ft_dot_inf(rayorig, c->center, c->axe)) - c->radius_2;
	delta = ft_disc(a, b, d);
	if (delta < 0)
		return (0);
	v->t0 = (-b - sqrt(delta)) / (2 * a);
	v->t1 = (-b + sqrt(delta)) / (2 * a);
	if (v->t0 <= 0 && v->t1 <= 0)
		return (0);
	return (1);
}

int		intersect_plan(t_sp *plan, t_vect3 *rayorig, t_vect3 *dir, double *t)
{
	double		d;

	if (!ft_dot(plan->normal, dir))
		return (0);
	d = ft_dot(plan->normal, plan->center);
	*t = -1 * (d + (ft_dot(plan->normal, rayorig) / ft_dot(plan->normal, dir)));
	if (*t < 0)
		return (0);
	return (2);
}
