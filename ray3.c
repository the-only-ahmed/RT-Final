/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 18:19:01 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/13 19:19:04 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec	depth_inf_maxdepth(t_raytracer *ray, t_rayparams *params, double refl)
{
	t_vec ret_refl;
	t_vec col2;
	t_vec ret_refl2;

	ret_refl2 = mul_vec(ray->r, EPSILON);
	ret_refl2 = add_vec(ray->pi, ray->r);
	params->dir = ray->r;
	params->o = ret_refl2;
	params->depth++;
	ret_refl = raytracer(params);
	col2 = mul_vec(ret_refl, refl);
	col2 = multi_vec(col2, ray->ret->col);
	return (add_vec(ray->color, col2));
}

void	reflexion(t_raytracer *ray, t_rayparams *params)
{
	double ret_dot;
	double refl;

	refl = ray->ret->reflection;
	if (refl > 0.0f)
	{
		ray->n = sub_vec(ray->pi, ray->ret->pos);
		ray->n = mul_vec(ray->n, 1.0f / ray->ret->radius);
		ret_dot = DOT(params->dir, ray->n) * 2.0f;
		ray->r = mul_vec(ray->n, ret_dot);
		ray->r = sub_vec(params->dir, ray->r);
		if (params->depth < MAX_DEPTH)
			ray->color = depth_inf_maxdepth(ray, params, refl);
	}
}

void	refraction(t_raytracer *ray, t_rayparams *params)
{
	t_refraction ref;

	if (ray->ret->refraction > 0 && params->depth < MAX_DEPTH)
	{
		ref.n_r = params->r_index / ray->ret->index_refraction;
		ref.n_ref = sub_vec(ray->pi, ray->ret->pos);
		ref.n_ref = mul_vec(ref.n_ref, 1.0f / ray->ret->radius);
		ref.cos_i = -DOT(ref.n_ref, params->dir);
		ref.cos_t2 = 1.0f - ref.n_r * ref.n_r * (1.0f - ref.cos_i * ref.cos_i);
		if (ref.cos_t2 > 0.0f)
		{
			ref.t_ref = mul_vec(params->dir, ref.n_r);
			ref.t_ref2 = ref.n_r * ref.cos_i - sqrtf(ref.cos_t2);
			ref.n_ref = mul_vec(ref.n_ref, ref.t_ref2);
			ref.t_ref = add_vec(ref.t_ref, ref.n_ref);
			ref.t_ref3 = mul_vec(ref.t_ref, EPSILON);
			ref.t_ref3 = add_vec(ray->pi, ref.t_ref3);
			params->dir = ref.t_ref;
			params->o = ref.t_ref3;
			params->depth++;
			params->r_index = ray->ret->index_refraction;
			ref.col_ref = raytracer(params);
			ray->color = add_vec(ray->color, ref.col_ref);
		}
	}
}
