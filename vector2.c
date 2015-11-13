/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 18:56:14 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/11/13 18:57:31 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec	multi_vec(t_vec a, t_vec b)
{
	t_vec ret;

	ret.x = a.x * b.x;
	ret.y = a.y * b.y;
	ret.w = a.w * b.w;
	return (ret);
}

t_vec	norm(t_vec a)
{
	double l;

	l = 1 / sqrtf(a.x * a.x + a.y * a.y + a.w * a.w);
	a.x *= l;
	a.y *= l;
	a.w *= l;
	return (a);
}

double	ft_dotw(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

double	ft_doty(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.w * v2.w);
}

double	ft_dotx(t_vec v1, t_vec v2)
{
	return (v1.w * v2.w + v1.y * v2.y);
}
