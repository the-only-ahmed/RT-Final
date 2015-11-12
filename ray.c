/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 14:45:38 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/12 19:19:44 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_nray(t_raytracer *ray, t_obj *l, t_vec dir, t_vec o)
{
	ray->shade = 1.0f;
	if (ray->tmp->type == SPHERE)
		tmp_type_sphere(ray, l);
	if (ray->ret->type == SPHERE)
	{
		ray->n = sub_vec(ray->pi, ray->ret->pos);
		ray->n = mul_vec(ray->n, 1.0f / ray->ret->radius);
	}
	else if (ray->ret->type == PLAN)
		ray->n = ray->ret->pos;
	else
		ray->n = set_nvec(ray->ret, dir, o, ray->ret2);
}

void	specular(t_raytracer *ray, t_vec dir)
{
	t_specular spc;

	if (ray->ret->specular > 0)
	{
		spc.r_spect = 2.0f * DOT(ray->l, ray->n);
		spc.r_spec = mul_vec(ray->n, spc.r_spect);
		spc.r_spec = sub_vec(ray->l, spc.r_spec);
		spc.dot_spec = DOT(dir, spc.r_spec);
		if (spc.dot_spec > 0)
		{
			spc.spect_diff = powf(spc.dot_spec, 20)
				* ray->ret->specular * ray->shade;
			spc.ret_spec = mul_vec(ray->tmp->col, spc.spect_diff);
			ray->color = add_vec(ray->color, spc.ret_spec);
		}
	}
}

void	shade(t_raytracer *ray, t_vec dir)
{
	if (ray->shade > 0)
	{
		ray->l = sub_vec(ray->tmp->pos, ray->pi);
		ray->l = norm(ray->l);
		if (ray->ret->diffuse > 0)
		{
			ray->dot = DOT(ray->n, ray->l);
			if (ray->dot > 0)
				ray->color = dot_positif(ray);
		}
		specular(ray, dir);
	}
}

t_vec	raytracer(t_rayparams *params)
{
	t_raytracer *ray;

	ray = init_ray(params->over.l);
	first_loop(ray, params->dir, params->o);
	if (!ray->ret)
		return (ray->color);
	*(params->distance) = ray->ret2;
	if (ray->ret->light == TRUE)
		return (set_vec(1, 1, 1));
	ray->pi = add_vec(params->o, mul_vec(params->dir, ray->ret2));
	ray->tmp = params->over.l;
	while (ray->tmp)
	{
		if (ray->tmp->light == TRUE)
		{
			set_nray(ray, params->over.l, params->dir, params->o);
			shade(ray, params->dir);
		}
		ray->tmp = ray->tmp->next;
	}
	reflexion(ray, params);
	refraction(ray, params);
	return (ray->color);
}
