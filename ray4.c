/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 18:44:59 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/16 12:48:50 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec			dot_positif(t_raytracer *ray)
{
	double	diff;
	t_vec	t;

	diff = ray->dot * ray->ret->diffuse * ray->shade;
	t = multi_vec(mul_vec(ray->ret->col, diff), ray->tmp->col);
	return (add_vec(ray->color, t));
}

void			first_loop(t_raytracer *ray, t_vec dir, t_vec o)
{
	while (ray->tmp)
	{
		return_i(ray, dir, o);
		if (ray->i > 0)
		{
			if (ray->ret)
			{
				if (ray->i > ray->ret2)
				{
					ray->tmp = ray->tmp->next;
					continue;
				}
			}
			ray->ret2 = ray->i;
			ray->ret = ray->tmp;
		}
		ray->tmp = ray->tmp->next;
	}
}

static t_vec	set_type_sphere(t_raytracer *ray)
{
	t_vec	l2;
	double	tdist;

	l2 = sub_vec(ray->tmp->pos, ray->pi);
	tdist = LENGTH(l2);
	l2 = mul_vec(l2, (1.0f / tdist));
	return (l2);
}

void			tmp_type_sphere(t_raytracer *ray, t_obj *l)
{
	t_vec o1;
	t_vec d1;
	t_obj *tmp2;

	d1 = set_type_sphere(ray);
	o1 = mul_vec(d1, EPSILON);
	o1 = add_vec(ray->pi, o1);
	tmp2 = l;
	while (tmp2)
	{
		if (tmp2->type != PLAN && tmp2->light == FALSE)
		{
			if (tmp2->type == SPHERE && hit_sphere(d1, o1, tmp2) > 0)
			{
				ray->shade = 0;
				break ;
			}
			else if (tmp2->type == CYLINDRE && hit_cyl(d1, o1, tmp2) > 0)
			{
				ray->shade = 0;
				break ;
			}
			/*else if (tmp2->type == CONE && ft_intercone(o1, d1, tmp2) > 0)
			{
				shade = 0;
				break ;
			}*/
		}
		tmp2 = tmp2->next;
	}
}
