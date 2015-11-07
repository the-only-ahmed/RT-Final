/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 03:10:48 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/26 19:13:06 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

double		ft_mix(double a, double b, double mix)
{
	double		res;

	res = (b * mix) + (a * (((double)(1)) - mix));
	return (res);
}

void		fn_normalize(t_vect3 *v)
{
	double		norm2;
	double		invnorm;

	norm2 = fn_length2(v);
	if (norm2 > 0)
	{
		invnorm = 1 / sqrt(norm2);
		v->x *= invnorm;
		v->y *= invnorm;
		v->z *= invnorm;
	}
}

double		fn_length2(t_vect3 *v)
{
	double		res;

	res = ft_pow(v->x, 2) + ft_pow(v->y, 2) + ft_pow(v->z, 2);
	return (res);
}

double		ft_pow(double x, int p)
{
	double		res;

	res = 1;
	while (p > 0)
	{
		res *= x;
		p--;
	}
	return (res);
}

double		ft_dot(t_vect3 *v1, t_vect3 *v2)
{
	double		res;

	res = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return (res);
}
