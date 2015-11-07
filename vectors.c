/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 02:21:45 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/26 19:15:11 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_vect3		*ft_vect_init(double x, double y, double z)
{
	t_vect3		*v;

	v = (t_vect3*)malloc(sizeof(t_vect3));
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vect3		*add_vect(t_vect3 *v1, t_vect3 *v2)
{
	t_vect3		*res;

	res = (t_vect3*)malloc(sizeof(t_vect3));
	res->x = v1->x + v2->x;
	res->y = v1->y + v2->y;
	res->z = v1->z + v2->z;
	return (res);
}

t_vect3		*sub_vect(t_vect3 *v1, t_vect3 *v2)
{
	t_vect3		*res;

	res = (t_vect3*)malloc(sizeof(t_vect3));
	res->x = v1->x - v2->x;
	res->y = v1->y - v2->y;
	res->z = v1->z - v2->z;
	return (res);
}

t_vect3		*mult_vect(t_vect3 *v1, t_vect3 *v2)
{
	t_vect3		*res;

	res = (t_vect3*)malloc(sizeof(t_vect3));
	res->x = v1->x * v2->x;
	res->y = v1->y * v2->y;
	res->z = v1->z * v2->z;
	return (res);
}

t_vect3		*mult_vectf(t_vect3 *v, double a)
{
	t_vect3		*res;

	res = (t_vect3*)malloc(sizeof(t_vect3));
	res->x = v->x * a;
	res->y = v->y * a;
	res->z = v->z * a;
	return (res);
}
